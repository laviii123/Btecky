import React, { useState, useEffect } from "react";
import Question from "./components/Question";
import questionsData from "./json/questions.json";

const App = () => {
  const [questions, setQuestions] = useState(questionsData);
  const [currentRound, setCurrentRound] = useState(1);
  const [currentQuestionIndex, setCurrentQuestionIndex] = useState(0);
  const [userAnswer, setUserAnswer] = useState(null);
  const [score, setScore] = useState(0);
  const [showNextRoundPrompt, setShowNextRoundPrompt] = useState(false);
  const [questionResults, setQuestionResults] = useState(
    Array(questionsData.length).fill(null)
  );

  const maxRounds = 10;
  const questionsPerRound = 10;

  const roundQuestions = questions.slice(
    (currentRound - 1) * questionsPerRound,
    currentRound * questionsPerRound
  );

  const resetQuestionStyles = () => {
    document.querySelectorAll(".option").forEach((element) => {
      element.style.backgroundColor = "";
      element.style.transform = "none";
    });
  };

  const handleAnswer = (selectedAnswer) => {
    const currentQuestion = roundQuestions[currentQuestionIndex];
    const isCorrect = selectedAnswer === currentQuestion.correctAnswer;

    if (isCorrect) {
      setScore(score + 1);
    }

    const resultsCopy = [...questionResults];
    resultsCopy[currentRound - 1 + currentQuestionIndex] = {
      correctAnswer: currentQuestion.correctAnswer,
      userAnswer: selectedAnswer,
    };
    setQuestionResults(resultsCopy);

    setUserAnswer(selectedAnswer);

    document.querySelectorAll(".option").forEach((element) => {
      const option = element.textContent;
      if (option === selectedAnswer) {
        element.style.backgroundColor = isCorrect ? "#A0FFA0" : "#FFA0A0";
        element.style.transform = isCorrect ? "scale(1.1)" : "none";
      } else if (option === currentQuestion.correctAnswer) {
        element.style.backgroundColor = "#A0FFA0";
        element.style.transform = "scale(1.1)";
      }
    });

    setTimeout(() => {
      handleNextQuestion();
    }, 2000); // Automatically transition to the next question after 2 seconds
  };

  const handleNextQuestion = () => {
    resetQuestionStyles();
    setUserAnswer(null);

    if (currentQuestionIndex < questionsPerRound - 1) {
      setCurrentQuestionIndex(currentQuestionIndex + 1);
    } else {
      if (currentRound < maxRounds) {
        setCurrentRound(currentRound + 1);
        setCurrentQuestionIndex(0);
        setShowNextRoundPrompt(true);
      } else {
        alert("End of the quiz");
      }
    }
  };

  const handleNextRound = () => {
    setCurrentRound(currentRound + 1);
    setCurrentQuestionIndex(0);
    setShowNextRoundPrompt(false);
  };

  const currentQuestion = roundQuestions[currentQuestionIndex];

  return (
    <div className="min-h-screen bg-gray-100 flex items-center justify-center">
      <div className="bg-white p-6 rounded-xl shadow-lg transition-all duration-300 ease-in-out hover:shadow-2xl relative w-[90%] md:h-[500px] md:w-[500px] mx-auto flex flex-col justify-center">
        <h1 className="text-2xl text-center uppercase font-bold pt-2 pb-4">
          Marvel Quiz
        </h1>
        <div className="flex justify-between">
          <div className="text-md font-semibold mb-4">
            Question {currentQuestionIndex + 1}/{questionsPerRound}
          </div>
          <div className="text-md font-semibold mb-4 ">
            Round {currentRound}/{maxRounds}
          </div>
        </div>
        <div className="text-lg text-center text-[#1fb31f] font-bold mb-4">
          Score: {score}
        </div>
        {showNextRoundPrompt ? (
          <div className="flex flex-col mb-4">
            <p className="text-lg text-center mb-2">
              Round {currentRound - 1} is over.
            </p>
            <button
              onClick={handleNextRound}
              className="border-2 bg-blue-500 text-white font-semibold border-blue-500 transition-all duration-300 ease-in-out hover:bg-white hover:text-blue-500 rounded-md p-2 m-1 cursor-pointer mt-4"
            >
              Play Round {currentRound}
            </button>
          </div>
        ) : (
          <>
            <Question
              dialogue={currentQuestion.dialogue}
              options={currentQuestion.options}
            />
            {currentQuestion.options.map((option, index) => (
              <div
                key={index}
                className={`bg-gray-100 option p-2 rounded-md m-1 cursor-pointer  ${
                  userAnswer === option ? "" : "hover:bg-blue-200"
                }`}
                onClick={() => {
                  if (!userAnswer) {
                    handleAnswer(option);
                  }
                }}
              >
                {option}
              </div>
            ))}
            <button
              onClick={handleNextQuestion}
              className="border-2 bg-blue-500 text-white font-semibold border-blue-500 transition-all duration-300 ease-in-out hover:bg-white hover:text-blue-500 rounded-md p-2 m-1 cursor-pointer mt-4"
            >
              Next Question
            </button>
          </>
        )}
      </div>
    </div>
  );
};

export default App;
