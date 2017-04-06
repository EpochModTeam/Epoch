pipeline {
  agent none
  stages {
    stage('checkout') {
      steps {
        node (label: 'testing') {
          checkout scm          
          fileExists 'README.md'
        }
      }
    }
  }
}
