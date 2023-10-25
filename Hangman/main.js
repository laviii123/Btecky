const buttons = document.querySelector('#buttons');

let c = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x', 'y', 'z'];

let clue_array = ["Holy", "Capital of India", "Financial capital of India", "CEO of Google(1st name)", "King of jungle","In front of you but can't be seen","Gets wet while drying","City which has largest Indian Museum", "Best IIT", "Best Club of IIT BHU" ]
let result_array = ["pious", "delhi", "mumbai", "sundar", "lion", "future", "towel", "kolkata","bhu", "cops"]
let entered = []
let prev_scores=[]
let g=0;

for (let i = 0; i < 26; i++) {
    const b1 = document.createElement('button');
    b1.id = 'b1';
    b1.style.cssText = "margin: 10px; color:white; background-color:green; padding: 15px;text-align: center; border-radius: 12px;"
    b1.textContent = c[i];
    b1.onclick = () => { entered += b1.textContent; b1.disabled = true; b1.style.backgroundColor = 'red'; play(); }


    buttons.appendChild(b1);

}

life = 10;
easy=document.querySelector('#easy')
hard=document.querySelector('#hard')
easy.onclick = () => {life=5; alert("START?"); hard.disabled=true; easy.disabled=true; countdown();}
hard.onclick = () => {life=10;alert("START?"); hard.disabled=true; easy.disabled=true;countdown();}
lives.textContent="Lives: "+life;
let idx = Math.floor(Math.random() * clue_array.length);
let clue = clue_array[idx];
let ans = result_array[idx];
result = document.querySelector('#result');
cluestat = document.querySelector('#clue');
lives=document.querySelector('#lives');
score=document.querySelector('.score')
again=document.querySelector('#again')
cluestat.textContent = clue + "  : \n\n(" + "Length of the word " +ans.length + ")" 
final_array = []
for (let i = 0; i < ans.length; i++) {
    final_array[i] = '_'; result.textContent += final_array[i];
}

console.log(ans);
let prev=0;


function play() {if(flag==0)return;

    for (let i = prev; i < entered.length; i++) {
        let f = 0;
        for (let j = 0; j < ans.length; j++) {


            if (entered[i] == [ans[j]]) {
                final_array[j] = entered[i]; f = 1;
                result.textContent = final_array.join(""); console.log(final_array);
            }
            let count__=0;
            for(let k=0;k<final_array.length;k++){if(final_array[k]=='_')count__++;}
            if(count__==0){(result.textContent+= " YOU WIN!"); 
           
           document.querySelectorAll('#b1').forEach(elem => {
            elem.disabled = true;
        });
        life=0;

        prev_scores[g++]=1+60-secs;
        const input= prev_scores[g-1]
        addTodos(input)
        
            return;}
            
        }
        if (f == 0) { life--; hang(); }
        if(life==0){  result.textContent="YOU GOT HANGED :("; 
        document.querySelectorAll('#b1').forEach(elem => {
            elem.disabled = true;
        });
        reveal = document.getElementById('reveal');
        reveal.textContent="Answer is : "+ ans
        prev_scores[g++]=0;
        const input= prev_scores[g-1]
        addTodos(input)
        lives.textContent="Lives: "+life;
return;
        }
    }
prev++;
if(life!=-1)
lives.textContent="Lives: "+life;
}










var hang = function () {
    var drawMe = life ;
    drawArray[drawMe]();
  }

  
   // Hangman
  canvas =  function(){

    man = document.getElementById("man");
    context = man.getContext('2d');
    
    context.beginPath();
    context.strokeStyle = "#fff";
    context.lineWidth = 2;
  };
  
    start_head = function(){
      man = document.getElementById("man");
      context = man.getContext('2d');
      context.beginPath();
      context.arc(60, 25, 10, 0, Math.PI*2, true);
      context.stroke();
    }
    
  draw = function($pathFromx, $pathFromy, $pathTox, $pathToy) {
    man = document.getElementById("man");  
    context = man.getContext('2d');
    context.moveTo($pathFromx, $pathFromy);
    context.lineTo($pathTox, $pathToy);
    context.stroke(); 
}

   f1 = function() {
     draw (0, 150, 150, 150);
   };
   
   f2 = function() {
     draw (10, 0, 10, 600);
   };
  
   f3 = function() {
     draw (0, 5, 70, 5);
   };
  
   f4 = function() {
     draw (60, 5, 60, 15);
   };
  
   ribs = function() {
     draw (60, 36, 60, 70);
   };
  
   right_hand = function() {
     draw (60, 46, 100, 50);
   };
  
   left_hand = function() {
     draw (60, 46, 20, 50);
   };
  
   right_leg = function() {
     draw (60, 70, 100, 100);
   };
  
   left_leg = function() {
     draw (60, 70, 20, 100);
   };
  
  drawArray = [right_leg, left_leg, right_hand, left_hand,  ribs,  start_head, f4, f3, f2, f1]; 


 
  

  var mins = 1;
  
        //calculate the seconds
        var secs = mins * 60;
  
        //countdown function is evoked when page is loaded
        function countdown() {
            setTimeout('Decrement()', 60);
        }
  let flag=1
        //Decrement function decrement the value.
        function Decrement() {
            if(life==0){flag=0;
                
        document.querySelectorAll('#b1').forEach(elem => {
            elem.disabled = true;
        });
                return;}
            if (document.getElementById) {
                minutes = document.getElementById("minutes");
                seconds = document.getElementById("seconds");
  
                //if less than a minute remaining
                //Display only seconds value.
                if (seconds < 59) {
                    seconds.value = secs;
                }
  
                //Display both minutes and seconds
                //getminutes and getseconds is used to
                //get minutes and seconds
                else {
                    minutes.value = getminutes();
                    seconds.value = getseconds();
                }
                //when less than a minute remaining
                //colour of the minutes and seconds
                //changes to red
                if (mins < 1) {
                    minutes.style.color = "red";
                    seconds.style.color = "red";
                }
                //if seconds becomes zero,
                //then page alert time up
                if (mins < 0) {
                    alert('time up');
                    minutes.value = 0;
                    seconds.value = 0;
                }
                //if seconds > 0 then seconds is decremented
                else {
                    secs--;
                    setTimeout('Decrement()', 1000);
                }
            }
        }
  
        function getminutes() {
            //minutes is seconds divided by 60, rounded down
            mins = Math.floor(secs / 60);
            return mins;
        }
  
        function getseconds() {
            //take minutes remaining (as seconds) away 
            //from total seconds remaining
            return secs - Math.round(mins * 60);
        }


        const todosUl = document.querySelector('.score')
        
        // const input = document.querySelector('#add')
        // const saveBtn = document.querySelector('#save')
        const getTodos = () => {
            let todos;
            if(localStorage.getItem('todos') === null){
                todos = [];
            }else {
                todos = JSON.parse(localStorage.getItem('todos'));
            }
            return todos;
        }
        const saveTodos = inputData => {
            const todos = getTodos();
            todos.push(inputData);
            localStorage.setItem('todos', JSON.stringify(todos));
        }
        const addTodos = (input) => {
            
        
            let li = document.createElement('li');
            li.textContent =  input;
            saveTodos(input);
            todosUl.appendChild(li);
            input = '';
        }
        const deleteTodos = (todos, e) => {
            const targetLi = todos.indexOf(e.target.textContent);
            todos.splice(targetLi, 1);
            localStorage.setItem('todos', JSON.stringify(todos));
        }

        // saveBtn.addEventListener('click', addTodos)

window.addEventListener('DOMContentLoaded', () => {
    const todos = getTodos()
        //show todos
    todos.forEach( todo => {
        let li = document.createElement('li');
        li.textContent =  todo;
        todosUl.appendChild(li)
        //delete todos
        li.addEventListener('dblclick', e => {
            deleteTodos(todos, e)
            todosUl.removeChild(li)
        })
    })
})