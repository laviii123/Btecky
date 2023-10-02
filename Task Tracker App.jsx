import React, { useState } from 'react';
import Task from './Task';
import './TaskTracker.css';

const TaskTracker = () => {
  const [tasks, setTasks] = useState([]);

  const addTask = (taskText) => {
    setTasks([...tasks, { id: Date.now(), text: taskText }]);
  };

  const deleteTask = (taskId) => {
    setTasks(tasks.filter((task) => task.id !== taskId));
  };

  return (
    <div className="task-tracker">
      <h1>Task Tracker</h1>
      <input
        type="text"
        placeholder="Add a task..."
        onKeyPress={(e) => {
          if (e.key === 'Enter') {
            addTask(e.target.value);
            e.target.value = '';
          }
        }}
      />
      <div className="task-list">
        {tasks.map((task) => (
          <Task key={task.id} task={task} onDelete={deleteTask} />
        ))}
      </div>
    </div>
  );
};

export default TaskTracker;
