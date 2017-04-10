pipeline {
  agent any
  stages {
    stage('checkout') {
      steps {
        ws(dir: 'C:/GITTEMP/FILES') {
          readFile 'README.md'
        }
        
      }
    }
    stage('Release') {
      steps {
        bat 'C:/GITTEMP/release.cmd'
      }
    }
  }
}