import React from 'react';
import { ImageBackground, StyleSheet, View, Text, TouchableOpacity, ScrollView } from 'react-native';

function WelcomeScreen() {
  return (
    <ScrollView contentContainerStyle={styles.scrollContainer}>
      <ImageBackground
        source={require("../../app/assets/sell-welcome.jpg")}
        style={styles.background}
        resizeMode="cover"
      >
        <View style={styles.overlay} />
        
        <View style={styles.titleContainer}>
          <Text style={styles.sellStuff}>Sell What You Don't Need</Text>
          <Text style={styles.subtitle}>Turn Your Clutter into Cash</Text>
        </View>

        <View style={styles.infoContainer}>
          <Text style={styles.infoTitle}>Why Choose Us?</Text>
          <Text style={styles.infoText}>• Easy to use platform</Text>
          <Text style={styles.infoText}>• Secure transactions</Text>
          <Text style={styles.infoText}>• Wide range of categories</Text>
          <Text style={styles.infoText}>• Connect with local buyers</Text>
        </View>

        <View style={styles.howItWorksContainer}>
          <Text style={styles.howItWorksTitle}>How It Works</Text>
          <Text style={styles.howItWorksStep}>1. Sign up for an account</Text>
          <Text style={styles.howItWorksStep}>2. List your items with photos</Text>
          <Text style={styles.howItWorksStep}>3. Set your price</Text>
          <Text style={styles.howItWorksStep}>4. Connect with buyers</Text>
          <Text style={styles.howItWorksStep}>5. Complete the sale</Text>
        </View>

        <View style={styles.testimonialContainer}>
          <Text style={styles.testimonialTitle}>What Our Users Say</Text>
          <Text style={styles.testimonialText}>
            "I've sold so many things I no longer need. This app is amazing!" - John D.
          </Text>
          <Text style={styles.testimonialText}>
            "Easy to use and great customer support. Highly recommended!" - Sarah M.
          </Text>
        </View>

        <View style={styles.buttonsContainer}>
          <TouchableOpacity style={styles.loginButton}>
            <Text style={styles.buttonText}>Login</Text>
          </TouchableOpacity>
          <TouchableOpacity style={styles.registerButton}>
            <Text style={styles.buttonText}>Register</Text>
          </TouchableOpacity>
        </View>

        <Text style={styles.termsText}>
          By using this app, you agree to our Terms of Service and Privacy Policy.
        </Text>
      </ImageBackground>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  scrollContainer: {
    flexGrow: 1,
  },
  background: {
    flex: 1,
    justifyContent: 'space-between',
    alignItems: 'center',
    paddingVertical: 40,
  },
  overlay: {
    ...StyleSheet.absoluteFillObject,
    backgroundColor: 'rgba(0,0,0,0.5)',
  },
  titleContainer: {
    alignItems: 'center',
    marginBottom: 20,
  },
  sellStuff: {
    fontSize: 28,
    fontWeight: 'bold',
    color: 'white',
    textAlign: 'center',
  },
  subtitle: {
    fontSize: 18,
    color: 'white',
    textAlign: 'center',
    marginTop: 10,
  },
  infoContainer: {
    width: '80%',
    backgroundColor: 'rgba(255,255,255,0.1)',
    padding: 20,
    borderRadius: 10,
    marginBottom: 20,
  },
  infoTitle: {
    fontSize: 20,
    fontWeight: 'bold',
    color: 'white',
    marginBottom: 10,
  },
  infoText: {
    color: 'white',
    marginBottom: 5,
  },
  howItWorksContainer: {
    width: '80%',
    backgroundColor: 'rgba(255,255,255,0.1)',
    padding: 20,
    borderRadius: 10,
    marginBottom: 20,
  },
  howItWorksTitle: {
    fontSize: 20,
    fontWeight: 'bold',
    color: 'white',
    marginBottom: 10,
  },
  howItWorksStep: {
    color: 'white',
    marginBottom: 5,
  },
  testimonialContainer: {
    width: '80%',
    backgroundColor: 'rgba(255,255,255,0.1)',
    padding: 20,
    borderRadius: 10,
    marginBottom: 20,
  },
  testimonialTitle: {
    fontSize: 20,
    fontWeight: 'bold',
    color: 'white',
    marginBottom: 10,
  },
  testimonialText: {
    color: 'white',
    fontStyle: 'italic',
    marginBottom: 10,
  },
  buttonsContainer: {
    width: '80%',
  },
  loginButton: {
    width: '100%',
    height: 70,
    backgroundColor: '#fc5c65',
    justifyContent: 'center',
    alignItems: 'center',
    borderRadius: 35,
    marginBottom: 20,
  },
  registerButton: {
    width: '100%',
    height: 70,
    backgroundColor: '#4ecdc4',
    justifyContent: 'center',
    alignItems: 'center',
    borderRadius: 35,
  },
  buttonText: {
    color: 'white',
    fontSize: 18,
    fontWeight: 'bold',
    textTransform: 'uppercase',
  },
  termsText: {
    color: 'white',
    textAlign: 'center',
    marginTop: 20,
    fontSize: 12,
  },
});

export default WelcomeScreen;