git使用简单总结：如何使用github远程仓库与本地连接

	1.注册github账号，安装GNU工具
	
	2.在远程仓库新建仓库Demo
	
	3.GIT工具下打开git bash，进行配置
	
	4.bash中输入
		git config --global user.name "CharlesBrer"
		git config --global user.email "3110942575@qq.com"
		配置好用户名和用户邮箱
	5.生成ssh-key
		ssh-keygen -t rsa -C "3110942575@qq.com"
	
	6.随后输入私人密码并确认（bxy）
	
	7.打开.ssh目录下的id/rsa.pub,全部复制，在github中的settings->ssh and gpg keys 中新建sshkey，
	  标题可以随便起，key中粘贴复制的内容
	
	8.在本地bash输入 ssh -T git@github.com
	
	9.在本地创建Demo文件夹，与远程仓库同步
	
	10.使用cd命令切换目录，当前为~即c:/users/lenovo
	
	11.切换到目录文件夹后，git init创建本地仓库，在本地生成.git文件夹
	
	12.连接远程仓库：
		git remote add origin git@github.com:CharlesBrer/Demo.git
	
	13.从远程仓库同步文件使用pull命令
		git pull origin master
		
	14.将本地文件同步到远程仓库
		git status 查看工作目录状态
		git add . 将当前目录下所有文件添加至暂存区
		git add <filename> 将指定文件添加到暂存区
		git commit -m "提交信息" 提交更改，添加备注，将暂存区的信息提交至本地仓库
		git push origin master 将本地仓库的文件push到远程仓库，若不成功后可加-f强推
		
		
