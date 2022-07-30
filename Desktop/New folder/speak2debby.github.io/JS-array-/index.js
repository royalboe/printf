/** @format */

let data = [
  { principal: 2500, time: 1.8 },
  { principal: 1000, time: 5 },
  { principal: 3000, time: 1 },
  { principal: 2000, time: 3 },
]

function interestCalculator(payload) {
  payload.map((obj) => {
    let rate = null
    if (obj.principal >= 2500 && obj.time > 1 && obj.time < 3) {
      rate = 3
    } else if (obj.principal >= 2500 && obj.time >= 3) {
      rate = 4
    } else if (obj.principal < 2500 || obj.time <= 1) {
      rate = 2
    } else {
      rate = 1
    }
    let interest = obj.principal * obj.time * rate

    let interestData = {
      ...obj,
      rate,
      interest,
    }
    console.log(interestData)
    return interestData
  })
}

interestCalculator(data)
