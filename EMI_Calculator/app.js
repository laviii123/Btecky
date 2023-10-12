const loanAmount = document.getElementById("loan_amount");
const loanTenure = document.getElementById("loan_tenure");
const loanRate = document.getElementById("loan_interest");

const loanEmi = document.querySelector(".loan_emi");
const loanPrinciple = document.querySelector(".loan_principle");
const loanTotal = document.querySelector(".loan_total");
const loanInterest = document.querySelector(".loan_interest_rate");
console.log("Developed By Ashish Gupta :)")



const submitBtn = document.querySelector(".calculator-btn");

submitBtn.addEventListener("click", function(){

    amount = loanAmount.value;
    tenure = (loanTenure.value); // 1Year = 12 months
    rate = (loanRate.value); // loan rate per year / 100 = loan percentage
    total= amount*(Math.pow(1+(rate/100),tenure)) //compound interest formula 
    emi = total/(tenure*12);
    // total = emi * tenure; // total amount to be paid including interest
    interest = total - amount // interest = total amount - principle amount
   

    loanEmi.innerHTML = Math.floor(emi);
    loanPrinciple.innerHTML = Math.floor(amount);
    loanTotal.innerHTML = Math.floor(total);
    loanInterest.innerHTML = Math.floor(interest);


    //Loanchart
    let xValues = ["Principle", "Interest"];
    let yValues = [amount, Math.floor(interest)];

    let barColors = ['rgba(255, 92, 138, 0.6)',
    ' rgba(96, 211, 148,0.6)'];

    new Chart("loanChart", {
        type: "polarArea",
        data: {
            labels: xValues,
            datasets:[{
                backgroundColor: barColors,
                data: yValues
            }]
        },
        options: {
            title: {
                display:false,
            }
        }
    });
  
    

});