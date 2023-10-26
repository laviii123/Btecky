const container = document.querySelector('.game-container');
const snake = document.getElementById('snake');
const food = document.getElementById('food');

let snakeX = 2;
let snakeY = 2;
let foodX = 5;
let foodY = 5;
let gridSize = 20;
let snakeXSpeed = 0;
let snakeYSpeed = 0;

function update() {
    snakeX += snakeXSpeed;
    snakeY += snakeYSpeed;

    // Check for collision with the food
    if (snakeX === foodX && snakeY === foodY) {
        foodX = Math.floor(Math.random() * (gridSize - 1));
        foodY = Math.floor(Math.random() * (gridSize - 1));
    }

    // Check for collision with the wall
    if (snakeX < 0 || snakeX >= gridSize || snakeY < 0 || snakeY >= gridSize) {
        alert('Game Over');
        location.reload(); // Reload the page to restart the game
        return;
    }

    snake.style.left = snakeX * gridSize + 'px';
    snake.style.top = snakeY * gridSize + 'px';
    food.style.left = foodX * gridSize + 'px';
    food.style.top = foodY * gridSize + 'px';

    requestAnimationFrame(update);
}

document.addEventListener('keydown', (event) => {
    switch (event.key) {
        case 'ArrowUp':
            snakeXSpeed = 0;
            snakeYSpeed = -1;
            break;
        case 'ArrowDown':
            snakeXSpeed = 0;
            snakeYSpeed = 1;
            break;
        case 'ArrowLeft':
            snakeXSpeed = -1;
            snakeYSpeed = 0;
            break;
        case 'ArrowRight':
            snakeXSpeed = 1;
            snakeYSpeed = 0;
            break;
    }
});

update();
