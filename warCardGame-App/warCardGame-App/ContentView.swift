//
//  ContentView.swift
//  warCardGame-App
//
//  Created by Austin Davis on 11/8/24.
//

import SwiftUI

struct ContentView: View {
    @State var playerCard = "card7"
    @State var cpuCard = "card13"
    @State var playerScore = 0
    @State var cpuScore = 0
    
    
    var body: some View {

        ZStack{
            // background color
            Color(red: 0.0, green: 0.5, blue: 0.0)
            
            // vstack for the ui
            VStack{
                Spacer()
                Image("logo").resizable().frame(width: 200, height: 100)
                Spacer()
                // hstack for the cards
                HStack{
                    Spacer()
                    Image(playerCard)
                    Spacer()
                    Image(cpuCard)
                    Spacer()
                    
                }
                
                // button for deal
                Spacer()
                
                Button {
                    deal()
                } label: {
                    Image("dealbutton")
                        .resizable()
                        .frame(width: 200, height: 100)
                }

                Spacer()
                HStack{
                    Spacer()
                    VStack{
                        Text("Player 1")
                            .font(.largeTitle)
                        Text(String(playerScore))
                            .font(.title)
                        
                    }
                    Spacer()
                    VStack{
                        Text("CPU")
                            .font(.largeTitle)

                        Text(String(cpuScore))
                            .font(.title)
                        
                    }
                    Spacer()

                }
                Spacer()
            }
            
            
            
            
            
            
            
        }.ignoresSafeArea()

        }
    
    func deal() {
        var playerCardVlaue = String(Int.random(in: 2...14))
        var cpuCardVlaue = String(Int.random(in: 2...14))
        // randomize the players card
        playerCard = "card" + playerCardVlaue
        // randomize the cpus card
        cpuCard = "card" + cpuCardVlaue
        //update the score
        if playerCardVlaue > cpuCardVlaue {
            playerScore += 1
        }
        else {
            cpuScore += 1
        }
        
        // say who wins in the console
        if playerScore >= 20 {
            print("Player 1 wins!")
        }
        else {
            print("The Cpu Wins")
        }
    }
    
    
    
    
    }

#Preview {
    ContentView()
}
