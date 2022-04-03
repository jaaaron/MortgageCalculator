#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#define PROP_TAX_RATE 0.0125 // year
#define UTILITIES 300.00 // month
#define INSURANCE 550.00 // year
using namespace std;

// Function Prototypes
void inputData(double& a,double& b,double& c);
void calcMonthlyCosts(double sellingPrice, double rateOfInterest, double numLoanYears);
void signature();
double subFunctionMulti(double a,double b);
double subFunctionMinus(double a,double b);

int main(int argc, const char * argv[]) {
    // Variables
    double sellingPrice, rateOfInterest, numLoanYears;
    
    // Input Data For Calculating Monthly Mortage Payments
    inputData(sellingPrice, rateOfInterest, numLoanYears);
    calcMonthlyCosts(sellingPrice, rateOfInterest, numLoanYears);
    signature();
    
    return 0;
}
// Function to Input All Data
void inputData(double& sellingPrice,double& rateOfInterest,double& numLoanYears){
/* Pre: sellingPrice - reference selling price
        rateOfInterest - reference rate of interest
        numLoanYears - reference rate of loan years
   Post: Nothing
   Purpose: Data Input
 */
    cout << "Selling Price? ";
    cin >> sellingPrice;
    cout << "Rate Of Interest? ";
    cin >> rateOfInterest;
    cout << "Number Of Years For The Loan? ";
    cin >> numLoanYears;
    cout << endl;
}
void calcMonthlyCosts(double sellingPrice, double rateOfInterest, double numLoanYears){
/* Pre: sellingPrice - reference selling price
        rateOfInterest - reference rate of interest
        numLoanYears - reference rate of loan years
   Post: Calculate Mortgage
   Purpose: compute and return the value
*/
    // Variables & Values
    const double down_payment = 0.20;
    double monthlyPayment, propTaxSum, insuranceMth, total, downPayment, loanAmount;
    
    // File Output
    std::ofstream outFile ("MortCalcu.txt", std::ofstream::out);
    
    // Compute Monthly Cost
    propTaxSum = (sellingPrice * PROP_TAX_RATE) / 12;
    insuranceMth = INSURANCE / 12;
    downPayment = subFunctionMulti(sellingPrice, down_payment);
    loanAmount = subFunctionMinus(sellingPrice, downPayment);
    monthlyPayment = (loanAmount / numLoanYears) / 12;//loanAmount; /// numLoanYears;
    total = monthlyPayment + UTILITIES + propTaxSum + insuranceMth;
    
    // Data to output .txt file
    outFile << "MONTHLY COST OF HOUSE" << endl;
    outFile << endl;
    outFile << setprecision(2) << fixed;
    outFile << "SELLING PRICE           " << setw(10) << sellingPrice << endl;
    outFile << "DOWN PAYMENT            " << setw(10) << downPayment << endl;
    outFile << "AMOUNT OF LOAN          " << setw(10) << loanAmount << endl;
    outFile << "INTEREST RATE           " << setw(10) << rateOfInterest << endl;
    outFile << "TAX RATE                " << setw(10) << PROP_TAX_RATE << endl;
    outFile << "DURATION OF LOAN (YEARS)" << setw(10) << numLoanYears << endl;
    outFile << endl;
    outFile << "MONTHLY PAYMENT         " << endl;
    outFile << "     MORTGAGE           " << setw(10) << monthlyPayment << endl;
    outFile << "     UTILITIES          " << setw(10) << UTILITIES << endl;
    outFile << "     PROPERTY TAXES     " << setw(10) << propTaxSum << endl;
    outFile << "     INSURANCE          " << setw(10) << insuranceMth << endl;
    outFile << "                         __________" << endl;
    outFile << "                        $ " << total << endl;
    outFile.close();
}
double subFunctionMulti(double a,double b){
    return a * b;
}
double subFunctionMinus(double a,double b){
    return a - b;
}
void signature(){
    cout << endl;
    cout << "Mortgage Monthly House Costs\n";
}
