const cells = document.querySelectorAll('.cell');
const status = document.getElementById('status');
const resetButton = document.getElementById('reset-button');
let currentPlayer = 'X';
let gameOver = false;

function checkWinner() {
    const winningCombinations = [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8],
        [0, 3, 6],
        [1, 4, 7],
        [2, 5, 8],
        [0, 4, 8],
        [2, 4, 6]
    ];

    for (const combination of winningCombinations) {
        const [a, b, c] = combination;
        if (cells[a].textContent && cells[a].textContent === cells[b].textContent && cells[a].textContent === cells[c].textContent) {
            cells[a].classList.add('winner');
            cells[b].classList.add('winner');
            cells[c].classList.add('winner');
            status.textContent = `Player ${currentPlayer} wins!`;
            gameOver = true;
        }
    }

    if (!cells.some(cell => cell.textContent === '')) {
        status.textContent = "It's a draw!";
        gameOver = true;
    }
}

function handleCellClick(event) {
    const cell = event.target;
    if (cell.textContent === '' && !gameOver) {
        cell.textContent = currentPlayer;
        checkWinner();
        currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
        status.textContent = `Player ${currentPlayer}'s turn`;
    }
}

function resetGame() {
    cells.forEach(cell => {
        cell.textContent = '';
        cell.classList.remove('winner');
    });
    currentPlayer = 'X';
    gameOver = false;
    status.textContent = "Player X's turn";
}

cells.forEach(cell => cell.addEventListener('click', handleCellClick));
resetButton.addEventListener('click', resetGame);
