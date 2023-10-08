const updateTime = () => {
    let d = new Date();
    usa.innerHTML = d.toLocaleString('en-US', {
        timeZone: 'America/Los_Angeles',
    }).split(", ")[1]

    india.innerHTML = d.toLocaleString('en-US', {
        timeZone: 'Asia/Kolkata',
    }).split(", ")[1]

    china.innerHTML = d.toLocaleString('en-US', {
        timeZone: 'Asia/Shanghai',
    }).split(", ")[1]

    japan.innerHTML = d.toLocaleString('en-US', {
        timeZone: 'Asia/Tokyo',
    }).split(", ")[1]

    australia.innerHTML = d.toLocaleString('en-US', {
        timeZone: 'Australia/Melbourne',
    }).split(", ")[1]

    europe.innerHTML = d.toLocaleString('en-US', {
        timeZone: 'Europe/Paris',
    }).split(", ")[1]

    let alarmhour = alarm.value.split(":")[0];
    let alarmmin = alarm.value.split(":")[1];

    if (d.getHours() == alarmhour && d.getMinutes() == alarmmin) {
        var audio = new Audio('alarm.mp3');
        audio.play();
    }

}
setInterval(updateTime, 1000);