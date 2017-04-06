pipeline {
  agent none
  stages {
    stage('checkout') {
      steps {
        node(label: 'testing') {
          script {
            checkout scm
          }
          
          fileExists 'README.md'
        }
        
      }
    }
  }
}