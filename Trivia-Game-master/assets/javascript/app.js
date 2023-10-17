// Javascript File
// A variable for the interval amount
var intervalId;
// An array holding question objects
var questionlist = [
  {
    Question: "What is the largest rodent found in North America?",
    Answer: { Name: "Beaver", Url: "assets/images/Beaver.mp4" },
    Wrong: ["Rat", "Squirrel", "Mouse"],
  },
  {
    Question: "The Dingo is a dog native to what country?",
    Answer: { Name: "Australia", Url: "assets/images/Dingo.mp4" },
    Wrong: ["Spain", "United States", "Great Britain"],
  },
  {
    Question: "What is the only bird that can fly backwards?",
    Answer: { Name: "Hummingbird", Url: "assets/images/Hummingbird-10281.mp4" },
    Wrong: ["Cockatiel", "Ostrich", "Peacock"],
  },
  {
    Question: "What horse breed is best used for racing?",
    Answer: { Name: "Thouroughbred", Url: "assets/images/Secretariat.mp4" },
    Wrong: ["Palomino", "Warmblood", "Shire"],
  },
  {
    Question: "What animal has the largest brain?",
    Answer: { Name: "Sperm Whale", Url: "assets/images/SpermWhale.mp4" },
    Wrong: ["Elephant", "Frog", "Human"],
  },
  {
    Question: "What is the only continent with no bees?",
    Answer: { Name: "Antarctica", Url: "assets/images/Antarctica.mp4" },
    Wrong: ["Africa", "Asia", "South America"],
  },
  {
    Question: "What is the tallest animal in the world?",
    Answer: { Name: "Giraffe", Url: "assets/images/Giraffe.mp4" },
    Wrong: ["Tiger", "Elephant", "Horse"],
  },
  {
    Question: "What is a flock of crows called?",
    Answer: { Name: "Murder", Url: "assets/images/Crow.mp4" },
    Wrong: ["Herd", "Pride", "Colony"],
  },
  {
    Question: "How many chambers in a dogs heart?",
    Answer: { Name: "Four", Url: "assets/images/DogHeart.mp4" },
    Wrong: ["Two", "Three", "Five"],
  },
  {
    Question: "A koalas diet consists mostly of leaves from what tree?",
    Answer: { Name: "Eucalyptus", Url: "assets/images/Koala.mp4" },
    Wrong: ["Aspen", "Fir", "Pine"],
  },
];

// Three variables for the results
var numRight = 0;
var numWrong = 0;
var numUnanswrd = 0;

window.customElements.define("progress-ring", ProgressRing);

// The main click event handler for starting the game
$("#start").on("click", function () {
  // Setting the game to start with the first question
  var i = 0;

  // A function for resetting the clock every 20 secs
  function resetClock() {
    // Clearing the question and answer div
    $("#qna-box").empty();

    // Twenty second start time
    var number = 20;
    // emulate progress attribute change
    var progress = 100;

    // Variables for the clock, question, and answer choice containers
    var newClock = $('<p id="clock" class="lead">Time remaining: (secs)</p>');
    var newTimeIndicator = $('<div id="time-indicator"></div>');
    newTimeIndicator.append(
      '<progress-ring stroke="4" radius="45" progress="100"></progress-ring>'
    );
    newTimeIndicator.append("<span></span>");
    var newQuestion = $(
      '<p id="question" class="lead">' + questionlist[i].Question + "</p>"
    );
    var newAnswerDiv = $('<div id="answers" class="list-group">');

    // Random number from 1 to 4
    var randomAnswrSpot = Math.floor(Math.random() * 4) + 1;

    // A variable for incrementing thru the wrong answers
    var k = 0;

    // Printing the four answer choices dynamically with the answer in random spot
    for (var j = 1; j < 5; j++) {
      var answerBtn = $('<button type="button"></button>');
      answerBtn.addClass(
        "list-group-item list-group-item-info list-group-item-action"
      );
      answerBtn.val(j);
      if (j == randomAnswrSpot) {
        answerBtn.text(questionlist[i].Answer.Name);
      } else {
        answerBtn.text(questionlist[i].Wrong[k]);
        k++;
      }
      newAnswerDiv.append(answerBtn);
    }
    // Dynamically adding the whole game box to DOM
    $("#qna-box")
      .append(newClock)
      .append(newTimeIndicator)
      .append(newQuestion)
      .append(newAnswerDiv);

    //  Decreasing the clock
    function decrement() {
      //  Decrease number by one.
      number--;
      progress -= 5;
      
      $("progress-ring").attr("progress", progress);
      $("#time-indicator span").text(number);

      if (number === 0) {
        // Run the stop function add 1 to unanswered questions
        stop();
        numUnanswrd++;
        // If not out of questions print answer add 1 to question count
        if (i < questionlist.length - 1) {
          printAnswer();
          i++;

          // Give the user 5 secs to see answer and video
          setTimeout(function () {
            resetClock();
          }, 5000);
        }
        // If out of questions print the last answer, wait 5 secs, then the game results
        else {
          printAnswer();
          setTimeout(function () {
            printResults();
            // On clicking restart button set all game variables back to 0
            $("#restart").on("click", function () {
              i = 0;
              numRight = 0;
              numWrong = 0;
              numUnanswrd = 0;
              resetClock();
            });
          }, 5000);
        }
      }
    }

    //  The stop function
    function stop() {
      //  Clears our intervalId
      //  We just pass the name of the interval
      //  to the clearInterval function.
      $("#clock").empty();
      $("#time-indicator").empty();
      clearInterval(intervalId);
    }

    // Start the clock and dynamically updating
    function run() {
      clearInterval(intervalId);
      intervalId = setInterval(decrement, 1000);
    }

    // Clearing the clock and question and answers and displaying the correct choice and video
    function printAnswer() {
      $("#answers").empty();

      var alertDiv = $('<div role="alert"></div>');
      alertDiv.addClass("alert alert-danger my-danger");
      alertDiv.text(
        "The correct answer is " + questionlist[i].Answer.Name + "!!!"
      );
      $("#answers").append(alertDiv);

      $("#answers").append(
        '<div id="answrMedia" style="margin:0 auto;"></div>'
      );

      var videoEl = $("<video loop autoplay></video>");
      videoEl.append(
        "<source src=" + questionlist[i].Answer.Url + "></source>"
      );
      $("#answrMedia").append(videoEl);
    }

    // The main click event handler for picking an answer
    $("button").on("click", function (e) {
      // Finding the question number for the user choice
      var valClicked = parseInt(e.target.value);
      // Empty the clock and answers
      $("#clock").empty();
      $("#answers").empty();
      // Print if correct or the correct answer if wrong
      if (valClicked == randomAnswrSpot) {
        numRight++;
        $("#answers").append(
          '<div class="alert alert-primary my-correct" role="alert">That is the correct answer!!!</div>'
        );
      } else {
        numWrong++;
        $("#answers").append(
          '<div class="alert alert-danger my-danger" role="alert">The correct answer is ' +
            questionlist[i].Answer.Name +
            "!!!</div>"
        );
      }
      // Add a container and the pertinent video for the answer
      $("#answers").append(
        '<div id="answrMedia" style="margin:0 auto;"></div>'
      );
      $("#answrMedia").append(
        "<video loop autoplay><source src=" +
          questionlist[i].Answer.Url +
          "></video"
      );
      // Reset the clock and the next question after displaying the answer
      if (i < questionlist.length - 1) {
        stop();
        i++;
        setTimeout(function () {
          resetClock();
        }, 5000);
      }
      // Stop the clock and print results if all questions answered
      else {
        stop();
        i++;
        setTimeout(function () {
          printResults();
          $("#restart").on("click", function () {
            i = 0;
            numRight = 0;
            numWrong = 0;
            numUnanswrd = 0;
            resetClock();
          });
        }, 5000);
      }
    });

    // Calling the run function
    run();
  }
  // Call to function for restarting the clock
  resetClock();
});

// A function for printing results at the end of the game
function printResults() {
  $("#qna-box").empty();
  $("#qna-box").append(
    '<div class="alert alert-success" role="alert" style="width: 66%; margin: 0 auto 10px;">Results</div>'
  );
  $("#qna-box").append("<p>You got " + numRight + " correct!</p>");
  $("#qna-box").append("<p>You got " + numWrong + " wrong!</p>");
  $("#qna-box").append(
    "<p>You left " + numUnanswrd + " questions unanswered!</p>"
  );
  $("#qna-box").append(
    '<button id="restart" type="button" class="btn btn-primary btn-lg">Restart Game</button>'
  );
}
