//////////////////////////////////////////////////////////////
//TIC TAC TOE
// Code starts here...

let player = 1;
let resultArr = [];
let playing = false;

const winningCombination = [
  [0, 1, 2],
  [3, 4, 5],
  [6, 7, 8],
  [0, 3, 6],
  [1, 4, 7],
  [2, 5, 8],
  [0, 4, 8],
  [2, 4, 6],
];

const tictactoe = function (num) {
  if (playing) {
    const ticTac = player ? "X" : "O";
    if (resultArr[num] !== 1 || resultArr[num] !== 0) {
      document.querySelector(`.cell--${num}`).textContent = ticTac;
      document.querySelector(`.cell--${num}`).style.fontSize = "60px";
      document.querySelector(`.cell--${num}`).style.fontWeight = "700";
      document.querySelector(`.cell--${num}`).style.color = "#ffb88c";

      resultArr[num] = Number(player);
      // console.log(resultArr);

      //Check for Player 1's win
      if (checkForWin(1)) {
        console.log("🎉Player 1 wins");
        document.querySelector(".winner--1").classList.remove("hidden");
        playing = false;
      }
      //Check for Player 2's win
      else if (checkForWin(0)) {
        console.log("🎉Player 2 wins");
        document.querySelector(".winner--2").classList.remove("hidden");
        playing = false;
      }
      player = !player;
      //Change the turn
    }
  }
};
//Click for your tic tac toe
for (let i = 0; i < 9; i++) {
  document
    .querySelector(`.cell--${i}`)
    .addEventListener("click", () => tictactoe(i));
}

//Check for Player's WIN
const checkForWin = function (player) {
  for (const combination of winningCombination) {
    const [a, b, c] = combination;
    if (
      resultArr[a] === player &&
      resultArr[b] === player &&
      resultArr[c] === player
    ) {
      return true;
    }
  }
  return false;
};

//Reload buttion
document.querySelector(".reload").addEventListener("click", function () {
  document.querySelectorAll(".cell").forEach((cell) => (cell.textContent = ""));
  resultArr = [];
  playing = true;
  player = 1;
  document.querySelector(".winner--1").classList.add("hidden");
  document.querySelector(".winner--2").classList.add("hidden");
  // console.log(ticTacToeaArr);
});

// setting up the start button
document.querySelector(".start--0").addEventListener("click", function () {
  document.querySelectorAll(".cell").forEach((cell) => (cell.textContent = ""));
  resultArr = [];
  player = 1;
  playing = true;
  document.querySelector(".winner--1").classList.add("hidden");
  document.querySelector(".winner--2").classList.add("hidden");
  console.log("START THE GAME");
});
