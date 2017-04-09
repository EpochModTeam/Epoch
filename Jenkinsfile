pipeline {
  agent any
  stages {
    stage('checkout') {
      steps {
        node(label: 'testing') {
          git(url: 'https://github.com/EpochModTeam/Epoch.git', branch: 'experimental')
        }
        
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