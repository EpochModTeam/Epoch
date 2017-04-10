pipeline {
  agent any
  stages {
    stage('checkout') {
      steps {
        node(label: 'testing') {
          git(url: 'https://github.com/EpochModTeam/Epoch.git', branch: 'experimental', credentialsId: 'github')
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