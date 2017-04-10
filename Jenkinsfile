pipeline {
  agent any
  stages {
    stage('checkout') {
      steps {
        pwd()
      }
    }
    stage('Release') {
      steps {
        bat 'C:/GITTEMP/release.cmd'
      }
    }
  }
}