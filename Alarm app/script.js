// Get references to various HTML elements
let alarm_btn = document.getElementById('alarm-btn'); // Button to edit alarms
let alarm_list = document.getElementById('alarms-list'); // List of alarms
let input = document.getElementById('inputs'); // Alarm input fields
let container = document.getElementsByClassName('container')[0]; // Main container
let save_alarm = document.getElementById('save-alarm'); // Button to save alarms
let p_alarm_list = alarm_list.getElementsByTagName('p'); // Paragraphs inside alarm list

// Function to toggle dark mode
function dark() {
    document.body.classList.toggle("dark"); // Toggle dark mode class on the body
    let button = document.getElementById("btn-mode");
    if (button.innerHTML === "Light mode") {
        button.innerHTML = "Dark mode";
        // Additional actions for switching to light mode can be added here
    } else {
        button.innerHTML = "Light mode";
        // Additional actions for switching to dark mode can be added here
    }
}

// Create an audio element for playing alarms
let audio = new Audio('./Music/m1.mp3');

// Check for alarms periodically
setInterval(() => {
    let a = new Date();
    let hour = a.getHours();
    let min = a.getMinutes();
    let sec = a.getSeconds();

    // Update displayed time
    document.getElementById("for-hour").innerHTML = hour;
    document.getElementById("for-min").innerHTML = min;
    document.getElementById("for-sec").innerHTML = sec;

    // Check if the current time matches the set alarm
    if (p_alarm_list[0].textContent == hour) {
        if (p_alarm_list[1].textContent == min) {
            if (p_alarm_list[2].textContent == sec) {
                console.log("Seconds matched");
                audio.play(); // Play the alarm sound
                audio.loop = true; // Loop the alarm sound
            }
        }
    }
}, 1000);

// Function to edit alarms when the "Edit Alarms" button is clicked
alarm_btn.onclick = function alarm_edit() {
    input.removeAttribute('hidden'); // Show the alarm input fields
};

// Function to save alarms when the "Save Alarm" button is clicked
save_alarm.onclick = function save_alarm() {
    let only_inputs = input.getElementsByTagName('input');

    // Check if all input fields are filled
    if (only_inputs[0].value !== '' && only_inputs[1].value !== '' && only_inputs[2].value !== '') {
        // Update the alarm list with the entered values
        alarm_list.innerHTML = `
            <h3>Alarm for :</h3>
            <h4>Hour : </h4>
            <p>${only_inputs[0].value}</p>
            <h4>Minute : </h4>
            <p>${only_inputs[1].value}</p>
            <h4>Seconds : </h4>
            <p>${only_inputs[2].value}</p>`;

        input.setAttribute('hidden', ''); // Hide the alarm input fields
        container.style.opacity = '1'; // Set the container opacity to 1
    } else {
        // Show an alert if input fields are not filled
        document.getElementById('alert').removeAttribute('hidden');
        setTimeout(() => {
            document.getElementById('alert').setAttribute('hidden', true);
        }, 4000); // Hide the alert after 4 seconds
    }
};
