pipeline {
  agent none
  stages {
    stage('checkout') {
      steps {
        node (label: 'testing') {
          checkout scm
          fileExists 'README.md'
          fileExists 'version.txt'
          fileExists 'build.txt'
          fileExists 'nonexistentFile.txt'
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
