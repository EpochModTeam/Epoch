pipeline {
  agent none
  stages {
    stage('checkout') {
      steps {
        node {
          checkout scm          
          fileExists 'README.md'
        }
      }
    }
  }
}
