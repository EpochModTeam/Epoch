pipeline {
  agent any
  stages {
    stage('checkout') {
      steps {
        fileExists 'DOESNOTEXIST.exe'
        fileExists 'README.md'
      }
    }
    stage('release') {
      steps {
        node(label: 'testing') {
          bat 'C:/GITTEMP/release.cmd'
        }
        
      }
    }
  }
}