const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const word = ["F", "O", "X"];
let chosen = Array(word.length).fill("_");
let remaining = word.length;

function guess(ch) {
  let matched = false;

  for (let i = 0; i < word.length; i++) {
    if (ch.toUpperCase() === word[i] && chosen[i] === "_") {
      chosen[i] = ch.toUpperCase();
      remaining -= 1;
      matched = true;
    }
  }

  if (matched) {
    console.log(`Letter matched: ${chosen.join(" ")}\nRemaining: ${remaining}`);
  } else {
    console.log(`Wrong guess: ${chosen.join(" ")}\nRemaining: ${remaining}`);
  }
}

function playGame() {
  if (remaining > 0) {
    rl.question("Enter a letter: ", (ans) => {
      if (ans && ans.length === 1) {
        guess(ans);
      } else {
        console.log("Please enter a single letter.");
      }

      if (remaining === 0) {
        console.log("Congratulations! You guessed the word: " + word.join(""));
        rl.close();
      } else {
        playGame();
      }
    });
  }
}//tricky one be careful!

playGame();