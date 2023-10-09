const gameContainer = document.querySelector('.game-container');
const snake = document.getElementById('snake');
const food = document.getElementById('food');

let snakeX = 0;
let snakeY = 0;
let foodX = 0;
let foodY = 0;
let snakeDirection = 'right';
let snakeSpeed = 100;
let score = 0;

function randomizeFoodPosition() {
    foodX = Math.floor(Math.random() * 29) * 10;
    foodY = Math.floor(Math.random() * 29) * 10;
    food.style.left = foodX + 'px';
    food.style.top = foodY + 'px';
}

function moveSnake() {
    switch (snakeDirection) {
        case 'up':
            snakeY -= 10;
            break;
        case 'down':
            snakeY += 10;
            break;
        case 'left':
            snakeX -= 10;
            break;
        case 'right':
            snakeX += 10;
            break;
    }

    snake.style.left = snakeX + 'px';
    snake.style.top = snakeY + 'px';

    if (snakeX === foodX && snakeY === foodY) {
        score++;
        randomizeFoodPosition();
        increaseSnakeSpeed();
    }
}

function increaseSnakeSpeed() {
    clearInterval(gameInterval);
    snakeSpeed -= 5;
    gameInterval = setInterval(moveSnake, snakeSpeed);
}

function checkCollision() {
    if (
        snakeX < 0 ||
        snakeX >= 300 ||
        snakeY < 0 ||
        snakeY >= 300
    ) {
        gameOver();
    }
}

function gameOver() {
    clearInterval(gameInterval);
    alert('Game Over! Your Score: ' + score);
    location.reload();
}

document.addEventListener('keydown', (e) => {
    switch (e.key) {
        case 'ArrowUp':
            if (snakeDirection !== 'down') {
                snakeDirection = 'up';
            }
            break;
        case 'ArrowDown':
            if (snakeDirection !== 'up') {
                snakeDirection = 'down';
            }
            break;
        case 'ArrowLeft':
            if (snakeDirection !== 'right') {
                snakeDirection = 'left';
            }
            break;
        case 'ArrowRight':
            if (snakeDirection !== 'left') {
                snakeDirection = 'right';
            }
            break;
    }
});

randomizeFoodPosition();
let gameInterval = setInterval(moveSnake, snakeSpeed);
