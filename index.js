document.addEventListener('DOMContentLoaded', function () {
    const temperatureInput = document.getElementById('temperature');
    const unit1Select = document.getElementById('unit1');
    const unit2Select = document.getElementById('unit2');
    const convertBtn = document.getElementById('convertBtn');
    const resultElement = document.getElementById('result');

    convertBtn.addEventListener('click', function () {
        const temperature = parseFloat(temperatureInput.value);
        const unit1 = unit1Select.value;
        const unit2 = unit2Select.value;
        let result;

        if (isNaN(temperature)) {
            result = 'Please enter a valid number.';
         }
         else if (unit1 === unit2) { 
            result = 'Please select different source and target units.';
        } 
         else {
            if (unit1 === 'celsius')
            {
                if(unit2 === 'fahrenheit')
            {
                const fahrenheit = (temperature * 9/5) + 32;
                result = `${temperature}°C is equal to ${fahrenheit.toFixed(2)}°F`;
            } 
            else if(unit2==='kelvin')
            {
                const kelvin =(temperature+273.15);
                result= `${temperature}°C is equal to ${kelvin.toFixed(2)}K`;
            }
            else if(unit2==='rankine')
            {
                const rankine=(temperature+273.15)*1.8;
                result=`${temperature}°C is equal to ${rankine.toFixed(2)}°R`;
            }
            else if(unit2==='reamur'){
                const reamur=temperature*0.8;
                result=`${temperature}°C is equal to ${reamur.toFixed(2)}°Re`;
        } } 
        else if (unit1 === 'fahrenheit')
        {
            if(unit2=='celsius')
            {
                const celsius=(temperature-32)/1.8;
                result=`${temperature}°F is equal to ${celsius.toFixed(2)}°C` ;
            } 
        else if(unit2=='kelvin')
        {
            const kelvin=(temperature+459.67)/1.8;
            result=`${temperature}°F is equal to ${kelvin.toFixed(2)}K `;
        }
        else if(unit2==="rankine")
        {
            const rankine=(temperature)+459.67;
            result=`${temperature}°F is equal to ${rankine.toFixed(2)}°R `;
        }
        else if(unit2==='reamur')
        {
            const reamur=(temperature-32)*4/9;
            result=`${temperature}°F is equal to ${reamur.toFixed(2)}°Re `;
        }
        }
        else if (unit1 == "kelvin"){
            if(unit2=="celsius")
            {
                const celsius= temperature - 273.15;
                result=`${temperature} K is equal to ${celsius.toFixed(2)} °C `;
            }
            else if(unit2=="fahrenheit")
            {
                const farenheit=(temperature*1.8)-459.67;
                result=`${temperature} K is equal to ${farenheit.toFixed(2)} F `;
            }
            else if(unit2=="rankine")
            {
                const rankine = temperature * 1.8 ;
                result=`${temperature} K is equal to ${rankine.toFixed(2)} °R `;
            }
            else if(unit2==='reamur')
            {
                const reamur =(temperature-273.15) * 0.8;
                result=`${temperature} K is equal to ${reamur.toFixed(2)} °Re `;
            }
            }
            else if(unit1==='rankine')
            {
                if(unit2==='celsius')
                {
                    const celsius=(temperature-491.67)/1.8;
                    result=`${temperature}°R is equal to ${celsius.toFixed(2)}°C`;
                }
                else if(unit2==='fahrenheit'){
                    const fahrenheit=(temperature-459.67);
                    result=`${temperature}°R is equal to ${fahrenheit.toFixed(2)}°F `;
                }
                else if(unit2==='kelvin')
                {
                    const kelvin=temperature/1.8;
                    result=`${temperature}°R is equal to ${kelvin.toFixed(2)}K `;
                }
                else if(unit2==='reamur'){
                    const reamur=(temperature-491.67)/1.8;
                    result=`${temperature}°R is equal to ${reamur.toFixed(2)}°Re `;
                }
            }
            else if(unit1==='reamur')
            {
                if(unit2==='celsius')
                {
                    const celsius=(temperature)*5/4;
                    result=`${temperature}°Re is equal to ${celsius.toFixed(2)}°C`
            } 
            else if(unit2==='fahrenheit')
            {
                const fahrenheit=(temperature*2.25)+32;
                result=`${temperature}°Re is equal to ${fahrenheit.toFixed(2)}°F `;
            }
            else if (unit2==="kelvin"){
                const kelvin=(temperature*1.25) + 273.15;
                result=`${temperature}°Re is equal to ${kelvin.toFixed(2)}K `;
            }
            else if(unit2==='rankine')
            {
                const rankine=temperature*9/4+491.67;
                result=`${temperature}°Re is equal to ${rankine.toFixed(2)}°R `;

            }}
        
        }

        resultElement.textContent = result;
    });
});

// Get the temperature input element
const temperatureInput1 = document.getElementById('temperature');

// Get the weather icon element
const weatherIcon = document.getElementById('weather-icon');

// Function to update the weather icon
function updateWeatherIcon(temperature) {
    if (temperature >= 30) {
        // Display a sun icon for high temperatures
        weatherIcon.innerHTML = '<img src="brightness-high-fill.svg" alt="Sun Icon">';
    } else if (temperature < 30 && temperature >= 10) {
        // Display a cloud icon for moderate temperatures
        weatherIcon.innerHTML = '<img src="cloud-fill.svg" alt="Cloud Icon">';
    } else {
        // Display a snowflake icon for low temperatures
        weatherIcon.innerHTML = '<img src="snow.svg" alt="Snowflake Icon">';
    }
}

// Event listener for temperature input changes
temperatureInput1.addEventListener('input', function () {
    const temperatureValue = parseFloat(temperatureInput1.value);

    if (!isNaN(temperatureValue)) {
        updateWeatherIcon(temperatureValue);
    } else {
        // Temperature input is not a valid number, clear the weather icon
        weatherIcon.innerHTML = '';
    }
});

// Event listener for the backspace key
temperatureInput1.addEventListener('keydown', function (event) {
    if (event.key === 'Backspace') {
        // Check if the input is empty (no value)
        if (temperatureInput1.value === '') {
            // Clear the weather icon
            weatherIcon.innerHTML = '';
           

        }
    }
});
// Get the temperature input element
const temperatureInput = document.getElementById('temperature');

// Get the body element
const body = document.body;

// Function to update the background based on temperature
function updateBackground(temperature) {
    if (temperature >= 30) {
        // Use a warm background for high temperatures
        body.style.backgroundImage = 'url(warm-bg.jpg)';

    } else if (temperature < 30 && temperature >= 10) {
        // Use a neutral background for moderate temperatures
        body.style.backgroundImage = 'url(neutral-bg.jpeg)';
    } else {
        // Use a cold background for low temperatures
        body.style.backgroundImage = 'url(cool-bg.jpg)';
    }
}
const resultElement = document.getElementById('result');
// Event listener for temperature input changes
temperatureInput.addEventListener('input', function () {
    const temperature = parseFloat(temperatureInput.value);

    if (!isNaN(temperature)) {
        updateBackground(temperature);
        resultElement.textContent = '';
        resultElement.style.backgroundColor = '';
    }
});

// Event listener for the backspace key

temperatureInput.addEventListener('keyup', function (event) {
    if (event.key === 'Backspace') {
        // Check if the input is empty (no value)
        if (temperatureInput.value === '') {
            // Clear the background image
            body.style.backgroundImage = '';
             const resultElement = document.getElementById('result');
            resultElement.style.backgroundColor = ''; // Reset background color to default

            // Clear the result text
            resultElement.textContent = ''; // Clear the result text
        
        }
    }
});
// Function to update the background color of the result element
function updateResultBackgroundColor(temperature) {
    const resultElement = document.getElementById('result');
    if (temperature >= 30) {
        // Set a warm background color for high temperatures
        resultElement.style.backgroundColor = 'rgb(218, 149, 12, 0.5)';
    } else if (temperature < 30 && temperature >= 10) {
        // Set a neutral background color for moderate temperatures
        resultElement.style.backgroundColor = 'rgb(195,195,195,50%)';
    } else {
        // Set a cold background color for low temperatures
        resultElement.style.backgroundColor = 'rgb(102,102,255,0.5)';
    }
}

// Event listener for temperature input changes
temperatureInput.addEventListener('input', function () {
    const temperature = parseFloat(temperatureInput.value);

    if (!isNaN(temperature)) {
        updateBackground(temperature);
        updateResultBackgroundColor(temperature); // Call the function to update the result element's background color
    }
});

// Event listener for the backspace key
temperatureInput.addEventListener('keyup', function (event) {
    if (event.key === 'Backspace') {
        // Check if the input is empty (no value)
        if (temperatureInput.value === '') {
            // Clear the background image
            body.style.backgroundImage = '';
            
            // Clear the result element's background color
            const resultElement = document.getElementById('result');
            resultElement.style.backgroundColor = ''; // Reset background color to default
        }
    }
});

