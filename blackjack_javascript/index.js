let playername = "Austin"
let chips = 125
let cards = []
let sum = 0
let hasBlackJack = false
let isAlive = false
let message = ""
let messageEl = document.getElementById("message-el")
let sumEl = document.getElementById("sum-el")
let cardsEl = document.getElementById("cards-el")
let playerEl = document.getElementById("player-el")
let wonEl = document.getElementById("won-el")

playerEl.textContent = playername + ": $ " + chips

function getRandomCard() {
    let randomNumber = Math.floor( Math.random()*13 ) + 1
    if (randomNumber > 10) {
        return 10
    } else if (randomNumber === 1) {
        return 11
    } else {
        return randomNumber
    }
}

function startGame() {
    isAlive = true
    let firstCard = getRandomCard()
    let secondCard = getRandomCard()
    cards = [firstCard, secondCard]
    sum = firstCard + secondCard
    wonEl.textContent = ""
    renderGame()
}

function subTokens() {
    if (isAlive === true) {
        chips -= 25
        let newPlayerChips = chips
        if (newPlayerChips >= 25) {
            playerEl.textContent = playername + ": $ " + newPlayerChips
        }else {
            wonEl.textContent = "You dont have enough money to play!"
        }
    }else {
        wonEl.textContent = "SORRY! TRY AGAIN!"

    }
}

function renderGame() {
    cardsEl.textContent = "Cards: "
    for (let i = 0; i < cards.length; i++) {
        cardsEl.textContent += cards[i] + " "
    
    }
    sumEl.textContent = "Sum: " + sum
    if (sum <= 20) {
        message = "Do you want to draw a new card?"
        subTokens()
    } else if (sum === 21) {
        message = "You've got Blackjack!"
        hasBlackJack = true
        chips += 100
        playerEl.textContent = playername + ": $ " + chips
        wonEl.textContent = "BLACKJACK!! YOU WIN 100$"
    } else {
        message = "You're out of the game!"
        isAlive = false
        subTokens()
    }
    messageEl.textContent = message
}

function newCard() {
    if (isAlive === true && hasBlackJack === false) {
        let card = getRandomCard()
        sum += card
        cards.push(card)
        renderGame()        
    }
}

function renderGame() {
    cardsEl.textContent = "Cards: "
    for (let i = 0; i < cards.length; i++) {
        cardsEl.textContent += cards[i] + " "
    }

    sumEl.textContent = "Sum: " + sum
    adjustForAce()  // Handle Aces dynamically

    if (sum <= 20) {
        message = "Do you want to draw a new card?"
        subTokens()
    } else if (sum === 21) {
        message = "You've got Blackjack!"
        hasBlackJack = true
        chips += 100
        playerEl.textContent = playername + ": $ " + chips
        wonEl.textContent = "BLACKJACK!! YOU WIN 100$"
    } else {
        message = "You're out of the game!"
        isAlive = false
        subTokens()
    }

    messageEl.textContent = message
}

