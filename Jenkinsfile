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
    stage('test') {
      steps {
        node (label: 'testing') {
          fileExists 'README.md'
        }
      }
    }
    stage('build') {
      steps {
        node (label: 'testing') {
          fileExists 'README.md'
          bat 'C:/GITTEMP/build.cmd'
        }
      }
    }
    stage('release') {
      steps {
        node (label: 'testing') {
          bat 'C:/GITTEMP/release.cmd'
        }
      }
    }
  }
}
