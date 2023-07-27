// Obtener los elementos del HTML
const form = document.getElementById("form");
const apps = document.querySelectorAll("#apps");
const tasks = document.querySelectorAll("#tasks");
const button = document.getElementById("start-stop");
const chart = document.getElementById("chart");

// Crear una variable para guardar el intervalo del conteo del tiempo
let interval;

// Crear una variable para guardar el tiempo usado en cada aplicación
let timeUsed = {};

// Crear una función para iniciar el conteo del tiempo
function startTimer() {
  // Obtener las aplicaciones seleccionadas por el usuario
  let selectedApps = [];
  for (let app of apps) {
    if (app.checked) {
      selectedApps.push(app.value);
    }
  }

  // Obtener las tareas programadas por el usuario
  let scheduledTasks = [];
  for (let i = 0; i < tasks.length; i += 2) {
    let taskName = tasks[i].value;
    let taskTime = tasks[i + 1].value;
    if (taskName && taskTime) {
      scheduledTasks.push({ name: taskName, time: taskTime });
    }
  }

  // Guardar las aplicaciones seleccionadas y las tareas programadas en el localStorage
  localStorage.setItem("selectedApps", JSON.stringify(selectedApps));
  localStorage.setItem("scheduledTasks", JSON.stringify(scheduledTasks));

  // Iniciar el intervalo del conteo del tiempo cada segundo
  interval = setInterval(() => {
    // Detectar la aplicación activa en el sistema operativo
    // Esta función depende del sistema operativo y puede variar según la implementación
    let activeApp = detectActiveApp();

    // Si la aplicación activa está entre las seleccionadas por el usuario, incrementar el tiempo usado en esa aplicación
    if (selectedApps.includes(activeApp)) {
      if (timeUsed[activeApp]) {
        timeUsed[activeApp]++;
      } else {
        timeUsed[activeApp] = 1;
      }
    }

    // Si hay alguna tarea programada que se cumpla con el tiempo transcurrido, mostrar una alerta al usuario
    for (let task of scheduledTasks) {
      if (timeUsed[activeApp] == task.time * 60) {
        alert(`Es hora de hacer la tarea: ${task.name}`);
      }
    }

    // Actualizar el gráfico del tiempo usado en cada aplicación
    updateChart();
  }, 1000);
}

// Crear una función para detener el conteo del tiempo
function stopTimer() {
  // Detener el intervalo del conteo del tiempo
  clearInterval(interval);
}

// Crear una función para actualizar el gráfico del tiempo usado en cada aplicación
function updateChart() {
  // Obtener los datos del tiempo usado en cada aplicación
  let data = [];
  for (let app in timeUsed) {
    data.push({ label: app, value: timeUsed[app] });
  }

  // Ordenar los datos de mayor a menor valor
  data.sort((a, b) => b.value - a.value);

  // Crear el gráfico usando Chart.js o Google Charts
  // Esta función depende de la librería que se use y puede variar según la implementación
  createChart(chart, data);
}

// Agregar un evento al botón para iniciar o detener el conteo del tiempo según su estado
button.addEventListener("click", () => {
  if (button.textContent == "Iniciar") {
    startTimer();
    button.textContent = "Detener";
  } else {
    stopTimer();
    button.textContent = "Iniciar";
  }
});

// Recuperar los datos guardados en el localStorage al cargar la página
window.addEventListener("load", () => {
  // Recuperar las aplicaciones seleccionadas y marcarlas en el formulario
  let selectedApps = JSON.parse(localStorage.getItem("selectedApps"));
  if (selectedApps) {
    for (let app of apps) {
      if (selectedApps.includes(app.value)) {
        app.checked = true;
      }
    }
  }
})