let gameseq=[];
let userseq=[];
let btn=["a","b","c","d"];
let level=0;
let started=false;
let h1=document.querySelector("h3");
document.addEventListener("keypress",()=>{
    if(started==false){
    started=true;
    levelup();
    }
})
function flash(btn1){
 btn1.classList.add("flash");
 setTimeout(()=>{
    btn1.classList.remove("flash");
 },300);
}
function levelup(){
    userseq=[];
    level++;
    h1.innerText=`Level-${level}`;
   let random= Math.floor(Math.random()*3);
   let bttn=document.querySelector(`.${btn[random]}`);
   gameseq.push(btn[random]);
   console.log(gameseq);
    flash(bttn);
}
// function userflash(h){
//     h.classList.add("f");
//     setTimeout(()=>{
//        h.classList.remove("f");
//     },300);
// }
function press(){
    let bo=this;
    flash(bo);
    let usercolor=bo.getAttribute("id");
    console.log(usercolor);
    userseq.push(usercolor);
    check(userseq.length-1);
}
let alll=document.querySelectorAll(".red");
for(btno of alll){
    btno.addEventListener("click",press);
}
function check(index){
if(gameseq[index]==userseq[index]){
    if(gameseq.length==userseq.length){
       setTimeout( levelup,1000);
    }
}else{
    h1.innerText=`Game Over!Your Score was:${level}, Press Any Key to restart! `;
    reset();
}
}
function reset(){
    started=false;
    gameseq=[];
    userseq=[];
    level=0;
}