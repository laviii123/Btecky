let alarm_btn = document.getElementById('alarm-btn')
let alarm_list = document.getElementById('alarms-list')
let input = document.getElementById('inputs')
let container = document.getElementsByClassName('container')[0]
let save_alarm = document.getElementById('save-alarm')
let p_alarm_list = alarm_list.getElementsByTagName('p')


function dark() {
    document.body.classList.toggle("dark")
    let button = document.getElementById("btn-mode");
    if (button.innerHTML === "Light mode") {
        button.innerHTML = "Dark mode";
        // Perform additional actions for switching to light mode
    } else {
        button.innerHTML = "Light mode";
        // Perform additional actions for switching to dark mode
    }
}

let audio = new Audio('./Music/m1.mp3');


setInterval(() => {
    let a = new Date();
    let hour = a.getHours();
    let min = a.getMinutes();
    let sec = a.getSeconds();

    document.getElementById("for-hour").innerHTML = hour
    document.getElementById("for-min").innerHTML = min
    document.getElementById("for-sec").innerHTML = sec

    if (p_alarm_list[0].textContent == hour) {
        // console.log("hour matched")
        if (p_alarm_list[1].textContent == min) {
            // console.log("minute mathed ");
            if (p_alarm_list[2].textContent == sec) {
                console.log("Seconds matched ");
                audio.play();
                audio.loop=true;
            }
        }
    }


}, 1000)


alarm_btn.onclick = function alarm_edit() {
    input.removeAttribute('hidden');
};

save_alarm.onclick = function save_alarm() {
    let only_inputs = input.getElementsByTagName('input')
    // only_inputs[0].value, only_inputs[1].value,only_inputs[2].

    if (only_inputs[0].value != '' && only_inputs[1].value !== '' && only_inputs[2].value !== '') {
        alarm_list.innerHTML = `
    <h3>Alarm for :</h3>
    <h4>Hour : </h4>
    <p>${only_inputs[0].value}</p>
    <h4>Minute : </h4>
    <p>${only_inputs[1].value}</p>
    <h4>Seconds : </h4>
    <p>${only_inputs[2].value}</p>`
        input.setAttribute('hidden', '');
        container.style.opacity = '1';
    }
    else {
        document.getElementById('alert').removeAttribute('hidden')
        setTimeout(() => {
            document.getElementById('alert').setAttribute('hidden', true)
        }, 4000);
    }
};
