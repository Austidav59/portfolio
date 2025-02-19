import { tweetsData } from './data.js'
import { v4 as uuidv4 } from 'https://jspm.dev/uuid';
let uuidString = ''

document.addEventListener('click', function(e){
    if(e.target.dataset.like){
       handleLikeClick(e.target.dataset.like) 
    }
    else if(e.target.dataset.retweet){
        handleRetweetClick(e.target.dataset.retweet)
    }
    else if(e.target.dataset.reply){
        handleReplyClick(e.target.dataset.reply)
    }
    else if(e.target.id === 'tweet-btn'){
        handleTweetBtnClick()
    }
    // handle tweet options
    else if(e.target.dataset.uuid){
        uuidString = e.target.dataset.uuid
        handleTweetOptions(e.target.dataset.uuid)
    }
    // Exit Button Clicked
    else if(e.target.id === 'exit-out'){
        handleExitOptionButton()
    }
    // Delete Button Clicked
    else if(e.target.id === 'delete'){
        handleDeleteButton(uuidString)
    }
    // Edit Button Clicked
    else if(e.target.id === 'edit'){

        handleEditTweetButton(uuidString)
    }
    else if(e.target.id === 'exit-out-editor'){
        handleExitEditButton()
    }
    else if(e.target.id === 'submit-edit'){
        handleSubmitEditButton(uuidString)
    }

})
 
function handleLikeClick(tweetId){ 
    const targetTweetObj = tweetsData.filter(function(tweet){
        return tweet.uuid === tweetId
    })[0]

    if (targetTweetObj.isLiked){
        targetTweetObj.likes--
    }
    else{
        targetTweetObj.likes++ 
    }
    targetTweetObj.isLiked = !targetTweetObj.isLiked
    render()
}

function handleRetweetClick(tweetId){
    const targetTweetObj = tweetsData.filter(function(tweet){
        return tweet.uuid === tweetId
    })[0]

    console.log(targetTweetObj)

    if(targetTweetObj.isRetweeted){
        targetTweetObj.retweets--
    }
    else{
        targetTweetObj.retweets++
    }
    targetTweetObj.isRetweeted = !targetTweetObj.isRetweeted
    render() 
}

function handleReplyClick(replyId){
    document.getElementById(`replies-${replyId}`).classList.toggle('hidden')
}

function handleTweetOptions(tweetId){
    const modalPopUp = document.getElementById('modal-pop-up')

    const targetTweetObj = tweetsData.filter(function(tweet){
        return tweet.uuid === tweetId
    })[0]

    tweetsData.forEach(function(tweet){
        if (modalPopUp){
            modalPopUp.innerHTML = 
            `
            <h1 class="rightside" id="exit-out">x</h1>
            <button class="optionbutton" id="delete" data-delete-uuid='${tweet.uuid}'>Delete</button>
            <button class="optionbutton" id="edit">Edit</button>
            `
            modalPopUp.style.display = 'flex'
        }

    })
    
}

function handleExitOptionButton(){
    const exitOut = document.getElementById('exit-out')

    if (exitOut){
        document.getElementById('modal-pop-up').style.display = 'none'
    }
}

function handleExitEditButton(){
    const exitOut = document.getElementById('exit-out-editor')

    if (exitOut){
        document.getElementById('modal-editor').style.display = 'none'
    }
}

function handleDeleteButton(tweetId) {
    const results = tweetsData.findIndex(function(tweet){
        return tweetId === tweet.uuid
    })

    let deleted = tweetsData.splice(results, 1)
    render()
}

function handleEditTweetButton(tweetId) {
    const modalEditor = document.getElementById('modal-editor')
    const targetTweetObj = tweetsData.filter(function(tweet){
        return tweet.uuid === tweetId
    })[0]

    if (targetTweetObj.handle === '@Scrimba'){
        const tweetText = targetTweetObj.tweetText

        modalEditor.innerHTML = 
        `
        <div class="dimension">
			<h1 class='exit-edit' id='exit-out-editor'>x<h1>
			<h1 class="title-edit" id="edit-title">Edit Tweet</h1>
            <textarea class="textarea-edit" id="edit-area-text">${tweetText}</textarea>
			<button id='submit-edit'>Submit</button>
		</div>
        `
        modalEditor.style.display = 'flex'
        document.getElementById('modal-pop-up').style.display = 'none'
    }
    else
    {
        console.log('You cant edit other peoples tweets!')
    }


}

function handleSubmitEditButton(tweetId){
    const editAreaText = document.getElementById('edit-area-text')
    const targetTweetObj = tweetsData.filter(function(tweet){
        return tweet.uuid === tweetId
    })[0]
    // set textArea value  to a const
    let newTextvalue = editAreaText.value
    // set new tweet text to objects text value 
    targetTweetObj.tweetText = newTextvalue
    // render the list of tweets
    render()
    // close mmodal pop up and cleat text field
    editAreaText.value = ""
    document.getElementById('modal-editor').style.display = 'none'
}

function handleTweetBtnClick(){
    const tweetInput = document.getElementById('tweet-input')

    if(tweetInput.value){
        tweetsData.unshift({
            handle: `@Scrimba`,
            profilePic: `images/scrimbalogo.png`,
            likes: 0,
            retweets: 0,
            tweetText: tweetInput.value,
            replies: [],
            isLiked: false,
            isRetweeted: false,
            uuid: uuidv4()
        })
    render()
    tweetInput.value = ''
    }

}


function getFeedHtml(){
    let feedHtml = ``
    
    tweetsData.forEach(function(tweet){
        
        let likeIconClass = ''
        
        if (tweet.isLiked){
            likeIconClass = 'liked'
        }
        
        let retweetIconClass = ''
        
        if (tweet.isRetweeted){
            retweetIconClass = 'retweeted'
        }
        
        let repliesHtml = ''
        
        if(tweet.replies.length > 0){
            tweet.replies.forEach(function(reply){
                repliesHtml+=`
<div class="tweet-reply">
    <div class="tweet-inner">
        <img src="${reply.profilePic}" class="profile-pic">
            <div>
                <p class="handle">${reply.handle}</p>
                <p class="tweet-text">${reply.tweetText}</p>
            </div>
        </div>
</div>
`
            })
        }
        
          
        feedHtml += `
<div class="tweet" id='tweets'>
    <div class="tweet-inner">
        <img src="${tweet.profilePic}" class="profile-pic">
        <div>
            <p class="handle">${tweet.handle}</p>
            <p class="tweet-text">${tweet.tweetText}</p>
            <div class="tweet-details">
                <span class="tweet-detail">
                    <i class="fa-regular fa-comment-dots"
                    data-reply="${tweet.uuid}"
                    ></i>
                    ${tweet.replies.length}
                </span>
                <span class="tweet-detail">
                    <i class="fa-solid fa-heart ${likeIconClass}"
                    data-like="${tweet.uuid}"
                    ></i>
                    ${tweet.likes}
                </span>
                <span class="tweet-detail">
                    <i class="fa-solid fa-retweet ${retweetIconClass}"
                    data-retweet="${tweet.uuid}"
                    ></i>
                    ${tweet.retweets}
                </span>
                <span class="tweet-detail" id="tweet-options" data-uuid="${tweet.uuid}">...</span>
            </div>   
        </div>            
    </div>
    <div class="hidden" id="replies-${tweet.uuid}">
        ${repliesHtml}
    </div>   
</div>
`
   })
   return feedHtml 
}

function render(){
    document.getElementById('feed').innerHTML = getFeedHtml()
}

render()

