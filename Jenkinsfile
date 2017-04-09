pipeline {
  agent any
  stages {
    stage('checkout') {
      steps {
        fileExists 'DOESNOTEXIST.exe'
        fileExists 'README.md'
      }
    }
    stage('Release') {
      steps {
        bat 'C:/GITTEMP/release.cmd'
      }
    }
  }
}