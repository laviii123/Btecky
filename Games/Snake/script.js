document.addEventListener('DOMContentLoaded', () => {
    const canvas = document.getElementById('game-board');
    const context = canvas.getContext('2d');
    const scale = 20;
    const rows = canvas.height / scale;
    const columns = canvas.width / scale;

    const snake = new Snake();
    const food = new Food();

    snake.draw();
    food.draw();

    window.setInterval(() => {
        context.clearRect(0, 0, canvas.width, canvas.height);
        snake.update();
        snake.draw();
        food.draw();

        if (snake.eat(food)) {
            food.pickLocation();
        }
    }, 100);
});
