// Get elements from the DOM
const taskForm = document.getElementById("task-form");
const taskInput = document.getElementById("task-input");
const taskList = document.getElementById("task-list");

// Add task to the list
function addTask(event) {
  event.preventDefault();

  if (taskInput.value === "") {
    alert("Please enter a task.");
    return;
  }

  const task = document.createElement("li");
  const taskText = document.createElement("span");
  taskText.textContent = taskInput.value;
  taskText.classList.add("task-text");

  const taskTimestamp = document.createElement("span");
  taskTimestamp.textContent = getFormattedTimestamp();
  taskTimestamp.classList.add("task-timestamp");

  const checkbox = document.createElement("input");
  checkbox.type = "checkbox";
  checkbox.addEventListener("mouseover", showConfirmation);
  checkbox.addEventListener("mouseout", hideConfirmation);
  checkbox.addEventListener("change", toggleTaskCompletion);

  const deleteButton = document.createElement("button");
  deleteButton.textContent = "Delete";
  deleteButton.classList.add("delete-button");
  deleteButton.addEventListener("click", deleteTask);

  const editButton = document.createElement("button");
  editButton.textContent = "Edit";
  editButton.classList.add("edit-button");
  editButton.addEventListener("click", editTask);

  task.appendChild(checkbox);
  task.appendChild(taskText);
  task.appendChild(taskTimestamp);
  task.appendChild(deleteButton);
  task.appendChild(editButton);
  taskList.appendChild(task);

  // Reset the task input
  taskInput.value = "";
}

// Show confirmation message on checkbox hover
function showConfirmation(event) {
  const confirmMessage = "Are you sure you want to check this task?";
  event.target.title = confirmMessage;
}

// Hide confirmation message on checkbox hover out
function hideConfirmation(event) {
  event.target.title = "";
}

// Toggle task completion
function toggleTaskCompletion(event) {
  const checkbox = event.target;
  const taskText = checkbox.nextElementSibling;

  if (!confirm("Are you sure you want to check this task?")) {
    checkbox.checked = false;
    return;
  }

  if (checkbox.checked) {
    taskText.style.textDecoration = "line-through";
  } else {
    taskText.style.textDecoration = "none";
  }
}

// Delete task from the list
function deleteTask(event) {
  const task = event.target.parentElement;
  taskList.removeChild(task);
}

// Edit task in the list
function editTask(event) {
  const task = event.target.parentElement;
  const taskText = task.querySelector(".task-text");
  const updatedTaskText = prompt("Enter the updated task:");
  if (updatedTaskText !== null) {
    taskText.textContent = updatedTaskText;
  }
}

// Get formatted timestamp
function getFormattedTimestamp() {
  const timestamp = new Date();
  return timestamp.toLocaleString();
}

// Event listener for task form submission
taskForm.addEventListener("submit", addTask);
