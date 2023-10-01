let currentInput = '';
let operator = '';

function appendNumber(num) {
    currentInput += num;
    updateDisplay();
}

function setOperator(op) {
    operator = op;
    currentInput += ` ${op} `;
    updateDisplay();
}

function calculateResult() {
    currentInput = eval(currentInput);
    updateDisplay();
}

function clearInput() {
    currentInput = '';
    operator = '';
    updateDisplay();
}

function updateDisplay() {
    document.getElementById('result').value = currentInput;
}

function appendOperator(op) {
    if (op === 'sqrt') {
        currentInput = Math.sqrt(currentInput);
    } else if (op === '^') {
        currentInput += '^';
    } else if (op === '!') {
        currentInput = factorial(parseInt(currentInput));
    }

    updateDisplay();
}

function factorial(n) {
    if (n === 0 || n === 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

