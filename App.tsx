import React from 'react';
import { View, StyleSheet } from 'react-native';
import WelcomeScreen from './app/screens/WelcomeScreen';
import { NavigationContainer } from '@react-navigation/native';

export default function App() {
  return (
    <View style={styles.container}>
      <WelcomeScreen />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    // Remove alignItems and justifyContent
  },
});