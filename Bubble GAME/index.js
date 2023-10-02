var randomNumber;
var score = 0;
var timer = 60;
var newTimer;

function makeBubble() {
  var ball = "";
  for (var i = 0; i <= 175; i++) {
    var rn = Math.floor(Math.random() * 10);
    ball = ball + `<div id="ballon">${rn}</div>`;
  }
  document.querySelector("#pbtm").innerHTML = ball;
  // document.getElementById("ballon");
}
makeBubble();

document.querySelector("#pbtm").addEventListener("click", function (details) {
  // alert("clicked");
  console.log(details.target.textContent);
  var clickednum = Number(details.target.textContent);
  if (clickednum === randomNumber) {
    increasescore();
    makeBubble();
    hitNumber();
  }
  // alert("clicked");
  // scoreval();
});

function runTimer() {
  newTimer = setInterval(function () {
    if (timer > 0) {
      timer--;

      document.querySelector("#timerInt").textContent = timer;
    } else {
      document.querySelector("#pbtm").innerHTML = "<h1>Game Over</h1>";
      clearInterval(newTimer);
    }
  }, 1000);
}

document.getElementById("btn").addEventListener("click", function () {
  runTimer();
});

function hitNumber() {
  randomNumber = Number(Math.floor(Math.random() * 10));
  document.querySelector("#hit").textContent = randomNumber;
}

function increasescore() {
  score = score + 10;
  document.querySelector("#scoreval").textContent = score;
}
// scoreval()

// document.getElementById("#pbtm").addEventListener("click",function(a){
//     alert("clicked")
//   })

// document.querySelector("#pbtm").addEventListener("click", function(){
//   alert("clicked");
// });
// makeBubble();

hitNumber();
