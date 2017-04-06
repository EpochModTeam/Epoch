pipeline {
  agent none
  stages {
    stage('Checkout') {
      steps {
        ws(dir: 'C:/GITTEMP') {
          script {
            checkout scm
          }
          
        }
        
      }
    }
  }
}