pipeline {
  agent none
  stages {
    stage('Checkout') {
      steps {
        fileExists 'README.md'
      }
    }
  }
}