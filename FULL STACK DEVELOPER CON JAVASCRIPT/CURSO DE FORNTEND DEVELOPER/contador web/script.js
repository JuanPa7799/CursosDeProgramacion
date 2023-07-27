let intervalId;
let startTime;
let elapsedTime = 0;

function formatTime(seconds) {
  const hrs = Math.floor(seconds / 3600);
  const mins = Math.floor((seconds % 3600) / 60);
  const secs = seconds % 60;

  return `${hrs.toString().padStart(2, '0')}:${mins.toString().padStart(2, '0')}:${secs.toString().padStart(2, '0')}`;
}

function updateTimer() {
  const currentTime = new Date().getTime();
  elapsedTime = Math.floor((currentTime - startTime) / 1000);
  document.getElementById('timeElapsed').textContent = formatTime(elapsedTime);
}

function startTimer() {
  const taskName = document.getElementById('taskName').value;
  if (taskName.trim() !== '') {
    startTime = new Date().getTime();
    intervalId = setInterval(updateTimer, 1000);
  }
}

function stopTimer() {
  clearInterval(intervalId);
  // Aquí puedes guardar la tarea y el tiempo en una base de datos o hacer otras operaciones con los datos.
}
