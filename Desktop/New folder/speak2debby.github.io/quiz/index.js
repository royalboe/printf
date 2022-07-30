const options=document.querySelector('.option').children;
const answerTrackerContainer=document.querySelector('.answer-tracker')
const questionNumberSpan= document.querySelector('.question-num-value');
const totalQuestionSpan= document.querySelector('.total-question');
const correctAnswerspan = document.querySelector('.correct-answers');
const totalQuestion = document.querySelector('.total-questions');
const totalPercentage = document.querySelector('.percentage');
const question= document.querySelector('.question');
const opt1 = document.querySelector(".option1");
const opt2 = document.querySelector(".option2");
const opt3 = document.querySelector(".option3");
const opt4 = document.querySelector(".option4");
let questionIndex;
let index=0;
let myArray=[];
let myArr=[];
let score=0;


// questions, options and answers

const questions=[
    {
        Q: 'What year did STartNG started',
        options: ['2017', '2013', '2014', '2018'],
        answer: 2,
    },
    {
        Q:'What is the most complicated language?',
        options:['ActionscriptC', 'C#', '.NETC++', 'Visual Basic'],
        answer:1,

    },
    {
        Q:'What does HTML stand for?',
        options: ['Hyper Trainer Marking Language', 'Hyper Text Marketing Language', 'Hyper Text Markup Language', 'Hyper Text Markup Leveler'],
        answer: 2,   
    },
    {
        Q: 'What is the most basic language Microsoft made?',
        options: ['Visual Basic', 'DirectX', 'Batch', 'C++'],
        answer: 0,

    },
    {
        Q: 'What is the correct way of making a header in HTML.',
        options: ['p tag', 'htmlheader tag', 'hh tag', 'h1 tag'],
        answer: 3, 
    }  
]

// set questions and question numbers
totalQuestionSpan.innerHTML=questions.length;
function load(){
    questionNumberSpan.innerHTML=index+1;
    question.innerHTML = questions[questionIndex].Q;
    opt1.innerHTML = questions[questionIndex].options[0];
    opt2.innerHTML = questions[questionIndex].options[1];
    opt3.innerHTML = questions[questionIndex].options[2];
    opt4.innerHTML = questions[questionIndex].options[3];
    index++;

}

function check(element) {
    if (element.id == questions[questionIndex].answer) {
        element.classList.add("correct");
        updateAnswerTracker('correct');
        score++;
        console.log('score:'+score);

    } else {
        element.classList.add("wrong");
        updateAnswerTracker('wrong');
    }
    disabledOptions()
}

function disabledOptions() {
    for (let i = 0; i < options.length; i++){
        options[i].classList.add('disabled');
        if (options[i].id==questions[questionIndex].answer){
            options[i].classList.add('correct');
        
        }
    }
}

function enabledOptions(){
    for (let i = 0; i < options.length; i++) {
        options[i].classList.remove('disabled', 'wrong', 'correct');

    }
}

function validate(){
    if (!options[0].classList.contains('disabled')){
        alert ('Please Select one option');
    }
    else{
        enabledOptions();
        randomQuestion();
    }

}
 
function next(){
    validate();
}
function randomQuestion() {
    let randomNumber = Math.floor(Math.random() * questions.length);
    let hitDuplicate=0;
    if(index==questions.length){
        quizOver()
    }
    else{
        if(myArray.length>0){
        for (let i = 0; i < myArray.length; i++){
            if(myArray[i]==randomNumber){
                hitDuplicate=1;
                break; 
            }

        }
        if (hitDuplicate==1){
            randomQuestion();
        }
        else{
        questionIndex = randomNumber; 
        load()
        myArr.push(questionIndex);

        }

        }
        if(myArray.length==0){
        questionIndex = randomNumber;
        load()
        myArr.push(questionIndex); 
        }

        myArray.push(randomNumber);
   
} 
}
function answerTrackers(){
    for(let i=0; i<questions.length; i++){
        const div=document.createElement('div')
        answerTrackerContainer.appendChild(div);
    }
}
function updateAnswerTracker(className){
answerTrackerContainer.children[index-1].classList.add(className); 
}

function quizOver() {
    document.querySelector('.quiz-over').classList.add('show');
    correctAnswerspan.innerHTML = score;
    totalQuestion.innerHTML=questions.length;
    totalPercentage.innerHTML=(score/questions.length)*100 +'%';

} 

function tryAgain(){
    window.location.reload();
}
    window.onload=function(){
        this.randomQuestion();
        this.answerTrackers(); 
     }

 