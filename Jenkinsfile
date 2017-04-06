pipeline {
  agent none
  stages {
    stage('checkout') {
      steps {
        node (label: 'testing') {
          checkout scm
        }
      }
    }
    stage('build') {
      steps {
        node (label: 'testing') {
          fileExists 'README.md'
        }
      }
    }
    stage('release') {
      steps {
        node (label: 'testing') {
          fileExists 'README.md'
        }
      }
    }
  }
}
