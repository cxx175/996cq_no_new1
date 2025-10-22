## Why
当前应用包名"load.tencent.lib"可能引起混淆，需要更改为更具描述性的"gd.game.lib"，以更好地反映应用的实际用途和功能。

## What Changes
- 将应用包名从"load.tencent.lib"更改为"gd.game.lib"
- 更新build.gradle中的applicationId和namespace配置
- 更新BlackObfuscator混淆配置中的包名
- 更新所有Java源文件中的包声明
- 更新AndroidManifest.xml中的引用

## Impact
- 受影响的规格: app配置
- 受影响的代码: app/build.gradle, AndroidManifest.xml, Java源文件包声明
- **BREAKING**: 这是一个破坏性变更，将影响应用的安装和更新机制
