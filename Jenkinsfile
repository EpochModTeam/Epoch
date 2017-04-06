pipeline {
  agent none
  stages {
    stage('Checkout') {
      steps {
        node(label: 'Checkout') {
          script {
            checkout scm
          }
          
        }
        
      }
    }
  }
}