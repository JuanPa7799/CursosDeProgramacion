export function solution(car) {
    if (car.licensePlate === null || car.licensePlate === undefined) {
      car.drivingLicense = false;
    }
    else {
      car.drivingLicense = true;
    }
    return car;
  }
  