<template>
  <div class="container">
    <h1>Vizualizace dat ze Sensor Hat</h1>

    <h2>Humidity ({{ humidity }}%)</h2>
    <canvas ref="humidityChart"></canvas>

    <h2>
      Temperature (HTS221: {{ temperature221 }} °C, LPS25H:
      {{ temperature25H }} °C)
    </h2>
    <canvas ref="temperatureChart"></canvas>

    <h2>Pressure ({{ pressure }} hPa)</h2>
    <canvas ref="pressureChart"></canvas>
  </div>
</template>

<script>
import { io } from "socket.io-client";
import Chart from "chart.js";

const socket = io();

export default {
  name: "App",
  data: () => ({
    humidity: 0,
    humidityChart: null,
    temperature221: 0,
    temperature25H: 0,
    temperatureChart: null,
    pressure: 0,
    pressureChart: null
  }),
  mounted() {
    this.humidityChart = new Chart(this.$refs.humidityChart, {
      type: "line",
      data: {
        datasets: [
          {
            label: "HTS221 Humidity",
            data: [],
            borderColor: "rgba(0, 0, 255, 0.5)",
            pointRadius: 0
          }
        ]
      },
      options: {
        scales: {
          xAxes: [
            {
              type: "time",
              distribution: "linear"
            }
          ],
          yAxes: [
            {
              ticks: {
                suggestedMin: 0,
                suggestedMax: 100,
                callback: value => `${value}%`
              }
            }
          ]
        },
        tooltips: {
          callbacks: {
            label: item => `${item.yLabel}%`
          }
        }
      }
    });

    this.temperatureChart = new Chart(this.$refs.temperatureChart, {
      type: "line",
      data: {
        datasets: [
          {
            label: "HTS221 Temperature",
            data: [],
            borderColor: "rgba(0, 0, 255, 0.5)",
            pointRadius: 0
          },
          {
            label: "LPS25H Temperature",
            data: [],
            borderColor: "rgba(255, 0, 0, 0.5)",
            pointRadius: 0
          }
        ]
      },
      options: {
        scales: {
          xAxes: [
            {
              type: "time",
              distribution: "linear"
            }
          ],
          yAxes: [
            {
              ticks: {
                suggestedMin: 0,
                suggestedMax: 50,
                callback: value => `${value} °C`
              }
            }
          ]
        },
        tooltips: {
          callbacks: {
            label: item => `${item.yLabel} °C`
          }
        }
      }
    });

    this.pressureChart = new Chart(this.$refs.pressureChart, {
      type: "line",
      data: {
        datasets: [
          {
            label: "LPS25H Pressure",
            data: [],
            borderColor: "rgba(0, 255, 0, 0.5)",
            pointRadius: 0
          }
        ]
      },
      options: {
        scales: {
          xAxes: [
            {
              type: "time",
              distribution: "linear"
            }
          ],
          yAxes: [
            {
              ticks: {
                suggestedMin: 970,
                suggestedMax: 1050,
                callback: value => `${value} hPa`
              }
            }
          ]
        },
        tooltips: {
          callbacks: {
            label: item => `${item.yLabel} hPa`
          }
        }
      }
    });

    socket.on("readings", readings => {
      for (const reading of readings) {
        const time = new Date(reading.timestamp * 1000);

        this.humidity = reading.hts221.humidity;
        this.temperature221 = reading.hts221.temperature;
        this.temperature25H = reading.lps25h.temperature;
        this.pressure = reading.lps25h.pressure;

        this.humidityChart.data.datasets[0].data.push({
          x: time,
          y: this.humidity
        });

        this.temperatureChart.data.datasets[0].data.push({
          x: time,
          y: this.temperature221
        });
        this.temperatureChart.data.datasets[1].data.push({
          x: time,
          y: this.temperature25H
        });

        this.pressureChart.data.datasets[0].data.push({
          x: time,
          y: this.pressure
        });
      }

      this.humidityChart.update();
      this.temperatureChart.update();
      this.pressureChart.update();
    });
  }
};
</script>

<style lang="scss"></style>
