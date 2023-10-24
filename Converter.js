function converter() {
    const input = parseFloat(document.getElementById('inputvalue').value);
    const FromUnit = document.getElementById('fromUnit').value;
    const toUnit = document.getElementById('toUnit').value;

    let result;

    if (FromUnit == 'meters' && toUnit == 'feet'){
        result = input * 3.28084;
    }
    else if (FromUnit == 'feet' && toUnit == 'meters'){
        result = input / 3.28084;
    }
    else if (FromUnit == 'meters' && toUnit == 'CentiMetres') {
        result = input * 100;
    }
    else if (FromUnit == 'CentiMetres' && toUnit == 'meters') {
        result = input / 100;
    }
    else if (FromUnit == 'feet' && toUnit == 'CentiMetres') {
        result = input * 30.48;
    }
    else if (FromUnit == 'CentiMetres' && toUnit == 'feet') {   
        result = input / 30.48;
    }
    else {
        result = input;
    }

    document.getElementById('result').innerHTML = `<h3>The converted value from ${FromUnit} to ${toUnit} is ${result} </h3>`;
}