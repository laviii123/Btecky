function rpsGame(yourChoice)
{
    // console.log(yourChoice);
    let humanChoice, botChoice;
    humanChoice = yourChoice.id;
    botChoice = IntToChoice(randomToInt());
    let results = decideWinner(humanChoice,botChoice); //[1,0] [0.5,0.5], [0,1]
    let message = finalMessage(results); // {msg: "win", color: "green"}
    rpsDisplay(humanChoice,botChoice,message);
    console.log(results);
    console.log(message);
}

function randomToInt()
{
    return Math.floor(Math.random()*3);
}

function IntToChoice(number)
{
    return ['rock', 'paper', 'scissor'][number];
}

function decideWinner(humanChoice, botChoice)
{
    let rpsDB = {
                    'rock':{'rock':0.5, 'paper':0, 'scissor':1},
                    'paper':{'rock':1, 'paper':0.5, 'scissor':0},
                    'scissor':{'rock':0, 'paper':1, 'scissor':0.5}
                }

    let yourScore = rpsDB[humanChoice][botChoice];
    let botScore = rpsDB[botChoice][humanChoice];

    return [yourScore,botScore];
}

function finalMessage([yourScore,botScore])
{
    if(yourScore === 0)
        return {'message' : 'You Lost!', 'color' : 'red'};
    else if(yourScore === 0.5)
        return {'message' : 'You Tied!', 'color' : 'yellow'};
    else
        return {'message' : 'You Won!', 'color' : 'green'};
}

function rpsDisplay(humanImgChoice, botImgChoice, message)
{
    let imgDB = {
                    'rock' : document.getElementById('rock').src,
                    'paper' : document.getElementById('paper').src,
                    'scissor' : document.getElementById('scissor').src,
                };

    document.getElementById('rock').remove();
    document.getElementById('paper').remove();
    document.getElementById('scissor').remove();

    let humanChoiceDiv = document.createElement('img');
    let botChoiceDiv = document.createElement('img');
    let messageDiv = document.createElement('div');

    humanChoiceDiv.src = imgDB[humanImgChoice];
    botChoiceDiv.src = imgDB[botImgChoice];

    humanChoiceDiv.style = "box-shadow: rgba(0, 0, 255, 0.56) 0px 22px 70px 4px;"
    messageDiv.innerHTML = "<h2 style='color:" + message.color + "; font-size:30px'>" + message.message + "</h2>"
    botChoiceDiv.style = "box-shadow: rgba(255, 0, 0, 0.56) 0px 22px 70px 4px;"

    document.getElementById('rps-div').appendChild(humanChoiceDiv);
    document.getElementById('rps-div').appendChild(messageDiv);
    document.getElementById('rps-div').appendChild(botChoiceDiv);
}
