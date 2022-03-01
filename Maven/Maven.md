## 基础篇

### 一、安装

1. 官网下载解压
2. 系统变量新建`MAVEN_HOME`，路径为MAVEN安装目录
3. path变量配置`%MAVEN_HOME%\bin`
4. 测试安装结果：cmd输入`mvn -v`

### 二、 仓库种类和彼此的关系

maven仓库：本地仓库、中央仓库、远程仓库（私服）、中央仓库。

1. 默认情况maven工程通过jar包坐标查找本地仓库，本地没有去中央仓库下载。

![本地仓库位置](.\本地仓库位置.png)

2.公司中：maven去本地仓库找jar包，本地找不到去远程仓库查找，远程仓库没有，可以本地上传或者去中央仓库查找。

3.使用`<localRepository>/path/to/local/repo</localRepository>`

修改本地jar仓库路径。

### 三、maven标准目录结构

maven项目标准目录结构：

* src/main/java目录： 核心代码部分
* src/main/resources: 配置文件部分
* src/test/java目录： 测试代码部分
* src/test/testsources: 测试配置文件
* src/main/webapp: 页面资源（js、css、图片等）

### 四、 基本命令

`mvn clean`：删除上次编译信息。

`mvn compile`: 编译

* 生成targeet目录

`mvn test`: 编译测试代码

* 生成的target目录里test-classes目录
* 编译源码和测试代码

`mvn package`： 打包

* java目录下的代码编译，test目录下的代码也被编译
* 生成war包

`mvn install`：

* 将项目打包
* 将项目jar包加入本地仓库

### 五、maven项目生命周期

![image-20200106124305900](生命周期.png)

### 六、maven概念模型图

<img src="模型.png"  />

### 七、IDEA 集成Maven插件

![](IDEA集成1.png)

<img src="IDEA集成2.png"  />

如果使用Maven骨架创建工程的话默认是需要联网的。配置此属性后，如果以前下载够配置工程相关的插件，就不用再联网（-DarchetypeCatalog=internal）。

![image-20200106172652628](IDEA集成3.png)

### 八、 创建Java工程

#### 1.使用骨架创建Maven项目

1. 新建项目

   ![image-20200106173007728](IDEA新建项目.png)

   * 右侧为IDEA提供的骨架/模板（视频使用的quickstart模板）

2. 键入坐标

   ![](项目坐标.png)

3. 具体包路径需要自己创建

   ![](Maven创建.png)

#### 2.不适用骨架创建Maven项目（推荐）

在使用骨架创建Maven项目第一步时去掉勾选使用骨架创建选项即可。

#### 3.使用骨架创建Web工程

1. 勾选以webapp结尾的骨架

2. 需手动在main目录下新建java目录，并右击java目录将该目录作为sources root

   ![](Maven新建web项目.png)

3. 本地仓库导入包文件

    在pom.xml文件中<dependencies>标签下加入<dependency>   </dependency>标签。

   ``` xml
   <!-- 加入依赖示例 -->
   <!-- 添加servlet包 --->
   <dependency>
     <groupId>javax.servlet</groupId>
     <artifactId>servlet-api</artifactId>
     <version>3.0-alpha-1</version>
   </dependency>
   <!-- 添加jsp ---->
   <dependency>
     <groupId>javax.servlet.jsp</groupId>
     <artifactId>jsp-api</artifactId>
     <version>2.2</version>
   </dependency>
   ```

4. IDEA使用Tomcat插件启动Maven项目

   在pom.xml文件<plugins>标签中插入如下

   ``` xml
   <plugin>
   <groupId>org.apache.tomcat.maven</groupId>
   <artifactId>tomcat7-maven-plugin</artifactId>
   <version>2.2</version>
   <configuration>
     <path>/</path>
     <!-- 端口号 -->
     <port>
       8080
     </port>
   </configuration>
   </plugin>
   ```
   

配置Tomcat:

<img src="MavenTomcat插件.png" style="zoom: 50%;" />

运行即可

![](MavenTomcat运行.png)

#### 4.运行产生的问题（jar包冲突）

本地Tomcat中的jsp包和servlet包与Maven导入的jar包冲突，运行时会出现错误。

解决：在冲突的包<dependency>标签中加上

``` xml
<scope>provided</scope>
```

标签。这样Maven导入的包只在写代码的时候起作用，项目运行时不起作用（Tomcat插件中的包起作用）。

同理

``` xml
<scope>test</scope>
```

表示只在测试时起作用。（适合导入的测试类用的包）

### 九、 Maven输出中文乱码问题

加入

```xml
    <properties>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
        <maven.compiler.encoding>UTF-8</maven.compiler.encoding>
        <java.version>1.8</java.version>
        <maven.compiler.source>1.8</maven.compiler.source>
        <maven.compiler.target>1.8</maven.compiler.target>
    </properties>
```

### 十、pom.xml

```xml

<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0http://maven.apache.org/maven-v4_0_0.xsd">
    <!--父项目的坐标。如果项目中没有规定某个元素的值，
那么父项目中的对应值即为项目的默认值。
坐标包括group ID，artifact ID和 version。-->
    <parent>
        <!--被继承的父项目的构件标识符-->
        <artifactId/>
        <!--被继承的父项目的全球唯一标识符-->
        <groupId/>
        <!--被继承的父项目的版本-->
        <version/>
    </parent>
    <!--声明项目描述符遵循哪一个POM模型版本。模型本身的版本很少改变，虽然如此，
   但它仍然是必不可少的，这是为了当Maven引入了新的特性或者其他模型变更的时候，
   确保稳定性。-->
    <modelVersion>4.0.0</modelVersion>
    <!--项目的全球唯一标识符，通常使用全限定的包名区分该项目和其他项目。
并且构建时生成的路径也是由此生成， 如com.mycompany.app生成的相对路径为：
/com/mycompany/app-->
    <groupId>cn.missbe.web</groupId>
    <!-- 构件的标识符，它和group ID一起唯一标识一个构件。换句话说，
你不能有两个不同的项目拥有同样的artifact ID和groupID；在某个
特定的group ID下，artifact ID也必须是唯一的。构件是项目产生的或使用的一个东西，
Maven为项目产生的构件包括：JARs，源码，二进制发布和WARs等。-->
    <artifactId>search-resources</artifactId>
    <!--项目产生的构件类型，例如jar、war、ear、pom。插件可以创建
他们自己的构件类型，所以前面列的不是全部构件类型-->
    <packaging>war</packaging>
    <!--项目当前版本，格式为:主版本.次版本.增量版本-限定版本号-->
    <version>1.0-SNAPSHOT</version>
    <!--项目的名称, Maven产生的文档用-->
    <name>search-resources</name>
    <!--项目主页的URL, Maven产生的文档用-->
    <url>http://www.missbe.cn</url>
    <!-- 项目的详细描述, Maven 产生的文档用。  当这个元素能够用HTML格式描述时
（例如，CDATA中的文本会被解析器忽略，就可以包含HTML标 签），
不鼓励使用纯文本描述。如果你需要修改产生的web站点的索引页面，
你应该修改你自己的索引页文件，而不是调整这里的文档。-->
    <description>A maven project to study maven.</description>
    <!--描述了这个项目构建环境中的前提条件。-->
    <prerequisites>
        <!--构建该项目或使用该插件所需要的Maven的最低版本-->
        <maven/>
    </prerequisites>

    <!--构建项目需要的信息-->
    <build>
        <!--该元素设置了项目源码目录，当构建项目的时候，
   构建系统会编译目录里的源码。该路径是相对于pom.xml的相对路径。-->
        <sourceDirectory/>
        <!--该元素设置了项目脚本源码目录，该目录和源码目录不同：
      绝大多数情况下，该目录下的内容 会被拷贝到输出目录(因为脚本是被解释的，而不是被编译的)。-->
        <scriptSourceDirectory/>
        <!--该元素设置了项目单元测试使用的源码目录，当测试项目的时候，
      构建系统会编译目录里的源码。该路径是相对于pom.xml的相对路径。-->
        <testSourceDirectory/>
        <!--被编译过的应用程序class文件存放的目录。-->
        <outputDirectory/>
        <!--被编译过的测试class文件存放的目录。-->
        <testOutputDirectory/>
        <!--使用来自该项目的一系列构建扩展-->
        <extensions>
            <!--描述使用到的构建扩展。-->
            <extension>
                <!--构建扩展的groupId-->
                <groupId/>
                <!--构建扩展的artifactId-->
                <artifactId/>
                <!--构建扩展的版本-->
                <version/>
            </extension>
        </extensions>

        <!--这个元素描述了项目相关的所有资源路径列表，例如和项目相关的属性文件，
      这些资源被包含在最终的打包文件里。-->
        <resources>
            <!--这个元素描述了项目相关或测试相关的所有资源路径-->
            <resource>
                <!-- 描述了资源的目标路径。该路径相对target/classes目录（例如${project.build.outputDirectory}）。举个例 子，如果你想资源在特定的包里(org.apache.maven.messages)，你就必须该元素设置为org/apache/maven /messages。
            然而，如果你只是想把资源放到源码目录结构里，就不需要该配置。-->
                <targetPath/>
                <!--是否使用参数值代替参数名。参数值取自properties元素或者文件里配置的属性，
            文件在filters元素里列出。-->
                <filtering/>
                <!--描述存放资源的目录，该路径相对POM路径-->
                <directory/>
                <!--包含的模式列表，例如**/*.xml.-->
                <includes/>
                <!--排除的模式列表，例如**/*.xml-->
                <excludes/>
            </resource>
        </resources>
        <!--这个元素描述了单元测试相关的所有资源路径，例如和单元测试相关的属性文件。-->
        <testResources>
            <!--这个元素描述了测试相关的所有资源路径，参见build/resources/resource元素的说明-->
            <testResource>
                <targetPath/><filtering/><directory/><includes/><excludes/>
            </testResource>
        </testResources>
        <!--构建产生的所有文件存放的目录-->
        <directory/>
        <!--产生的构件的文件名，默认值是${artifactId}-${version}。-->
        <finalName/>
        <!--当filtering开关打开时，使用到的过滤器属性文件列表-->
        <filters/>
        <!--子项目可以引用的默认插件信息。该插件配置项直到被引用时才会被解析或绑定到生命周期。
      给定插件的任何本地配置都会覆盖这里的配置-->
        <pluginManagement>
            <!--使用的插件列表 。-->
            <plugins>
                <!--plugin元素包含描述插件所需要的信息。-->
                <plugin>
                    <!--插件在仓库里的group ID-->
                    <groupId/>
                    <!--插件在仓库里的artifact ID-->
                    <artifactId/>
                    <!--被使用的插件的版本（或版本范围）-->
                    <version/>
                    <!--是否从该插件下载Maven扩展（例如打包和类型处理器），由于性能原因，
               只有在真需要下载时，该元素才被设置成enabled。-->
                    <extensions/>
                    <!--在构建生命周期中执行一组目标的配置。每个目标可能有不同的配置。-->
                    <executions>
                        <!--execution元素包含了插件执行需要的信息-->
                        <execution>
                            <!--执行目标的标识符，用于标识构建过程中的目标，或者匹配继承过程中需要合并的执行目标-->
                            <id/>
                            <!--绑定了目标的构建生命周期阶段，如果省略，目标会被绑定到源数据里配置的默认阶段-->
                            <phase/>
                            <!--配置的执行目标-->
                            <goals/>
                            <!--配置是否被传播到子POM-->
                            <inherited/>
                            <!--作为DOM对象的配置-->
                            <configuration/>
                        </execution>
                    </executions>
                    <!--项目引入插件所需要的额外依赖-->
                    <dependencies>
                        <!--参见dependencies/dependency元素-->
                        <dependency>
                            ......
                        </dependency>
                    </dependencies>
                    <!--任何配置是否被传播到子项目-->
                    <inherited/>
                    <!--作为DOM对象的配置-->
                    <configuration/>
                </plugin>
            </plugins>
        </pluginManagement>
        <!--使用的插件列表-->
        <plugins>
            <!--参见build/pluginManagement/plugins/plugin元素-->
            <plugin>
                <groupId/><artifactId/><version/><extensions/>
                <executions>
                    <execution>
                        <id/><phase/><goals/><inherited/><configuration/>
                    </execution>
                </executions>
                <dependencies>
                    <!--参见dependencies/dependency元素-->
                    <dependency>
                        ......
                    </dependency>
                </dependencies>
                <goals/><inherited/><configuration/>
            </plugin>
        </plugins>
    </build>
    <!--模块（有时称作子项目） 被构建成项目的一部分。
   列出的每个模块元素是指向该模块的目录的相对路径-->
    <modules/>
    <!--发现依赖和扩展的远程仓库列表。-->
    <repositories>
        <!--包含需要连接到远程仓库的信息-->
        <repository>
            <!--如何处理远程仓库里发布版本的下载-->
            <releases>
                <!--true或者false表示该仓库是否为下载某种类型构件（发布版，快照版）开启。 -->
                <enabled/>
                <!--该元素指定更新发生的频率。Maven会比较本地POM和远程POM的时间戳。这里的选项是：always（一直），daily（默认，每日），interval：X（这里X是以分钟为单位的时间间隔），或者never（从不）。-->
                <updatePolicy/>
                <!--当Maven验证构件校验文件失败时该怎么做：ignore（忽略），fail（失败），或者warn（警告）。-->
                <checksumPolicy/>
            </releases>
            <!-- 如何处理远程仓库里快照版本的下载。有了releases和snapshots这两组配置，
         POM就可以在每个单独的仓库中，为每种类型的构件采取不同的 策略。
         例如，可能有人会决定只为开发目的开启对快照版本下载的支持。
         参见repositories/repository/releases元素 -->
            <snapshots>
                <enabled/><updatePolicy/><checksumPolicy/>
            </snapshots>
            <!--远程仓库唯一标识符。可以用来匹配在settings.xml文件里配置的远程仓库-->
            <id>banseon-repository-proxy</id>
            <!--远程仓库名称-->
            <name>banseon-repository-proxy</name>
            <!--远程仓库URL，按protocol://hostname/path形式-->
            <url>http://192.168.1.169:9999/repository/</url>
            <!-- 用于定位和排序构件的仓库布局类型-可以是default（默认）或者legacy（遗留）。Maven 2为其仓库提供了一个默认的布局；然 而，Maven 1.x有一种不同的布局。我们可以使用该元素指定布局是default（默认）还是legacy（遗留）。-->
            <layout>default</layout>
        </repository>
    </repositories>
    <!--发现插件的远程仓库列表，这些插件用于构建和报表-->
    <pluginRepositories>
        <!--包含需要连接到远程插件仓库的信息.参见repositories/repository元素-->
        <pluginRepository>
            ......
        </pluginRepository>
    </pluginRepositories>

    <!--该元素描述了项目相关的所有依赖。 这些依赖组成了项目构建过程中的一个个环节。
它们自动从项目定义的仓库中下载。要获取更多信息，请看项目依赖机制。-->
    <dependencies>
        <dependency>
            <!--依赖的group ID-->
            <groupId>org.apache.maven</groupId>
            <!--依赖的artifact ID-->
            <artifactId>maven-artifact</artifactId>
            <!--依赖的版本号。 在Maven 2里, 也可以配置成版本号的范围。-->
            <version>3.8.1</version>
            <!-- 依赖类型，默认类型是jar。它通常表示依赖的文件的扩展名，但也有例外
。一个类型可以被映射成另外一个扩展名或分类器。类型经常和使用的打包方式对应，
 尽管这也有例外。一些类型的例子：jar，war，ejb-client和test-jar。
如果设置extensions为 true，就可以在 plugin里定义新的类型。所以前面的类型的例子不完整。-->
            <type>jar</type>
            <!-- 依赖的分类器。分类器可以区分属于同一个POM，但不同构建方式的构件。
分类器名被附加到文件名的版本号后面。例如，如果你想要构建两个单独的构件成 JAR，
一个使用Java 1.4编译器，另一个使用Java 6编译器，你就可以使用分类器来生成两个单独的JAR构件。-->
            <classifier></classifier>
            <!--依赖范围。在项目发布过程中，帮助决定哪些构件被包括进来。欲知详情请参考依赖机制。
                - compile ：默认范围，用于编译
                - provided：类似于编译，但支持你期待jdk或者容器提供，类似于classpath
                - runtime: 在执行时需要使用
                - test:    用于test任务时使用
                - system: 需要外在提供相应的元素。通过systemPath来取得
                - systemPath: 仅用于范围为system。提供相应的路径
                - optional:   当项目自身被依赖时，标注依赖是否传递。用于连续依赖时使用-->
            <scope>test</scope>
            <!--仅供system范围使用。注意，不鼓励使用这个元素，
并且在新的版本中该元素可能被覆盖掉。该元素为依赖规定了文件系统上的路径。
需要绝对路径而不是相对路径。推荐使用属性匹配绝对路径，例如${java.home}。-->
            <systemPath></systemPath>
            <!--当计算传递依赖时， 从依赖构件列表里，列出被排除的依赖构件集。
即告诉maven你只依赖指定的项目，不依赖项目的依赖。此元素主要用于解决版本冲突问题-->
            <exclusions>
                <exclusion>
                    <artifactId>spring-core</artifactId>
                    <groupId>org.springframework</groupId>
                </exclusion>
            </exclusions>
            <!--可选依赖，如果你在项目B中把C依赖声明为可选，你就需要在依赖于B的项目（例如项目A）中显式的引用对C的依赖。可选依赖阻断依赖的传递性。-->
            <optional>true</optional>
        </dependency>
    </dependencies>


    <!-- 继承自该项目的所有子项目的默认依赖信息。这部分的依赖信息不会被立即解析,
   而是当子项目声明一个依赖（必须描述group ID和 artifact ID信息），
   如果group ID和artifact ID以外的一些信息没有描述，
   则通过group ID和artifact ID 匹配到这里的依赖，并使用这里的依赖信息。-->
    <dependencyManagement>
        <dependencies>
            <!--参见dependencies/dependency元素-->
            <dependency>
                ......
            </dependency>
        </dependencies>
    </dependencyManagement>
    <!--项目分发信息，在执行mvn deploy后表示要发布的位置。
有了这些信息就可以把网站部署到远程服务器或者把构件部署到远程仓库。-->
    <distributionManagement>
        <!--部署项目产生的构件到远程仓库需要的信息-->
        <repository>
            <!--是分配给快照一个唯一的版本号（由时间戳和构建流水号）？
   还是每次都使用相同的版本号？参见repositories/repository元素-->
            <uniqueVersion/>
            <id>banseon-maven2</id>
            <name>banseon maven2</name>
            <url>file://${basedir}/target/deploy</url>
            <layout/>
        </repository>
        <!--构件的快照部署到哪里？如果没有配置该元素，默认部署到repository元素配置的仓库，
      参见distributionManagement/repository元素-->
        <snapshotRepository>
            <uniqueVersion/>
            <id>banseon-maven2</id>
            <name>Banseon-maven2 Snapshot Repository</name>
            <url>scp://svn.baidu.com/banseon:/usr/local/maven-snapshot</url>
            <layout/>
        </snapshotRepository>
        <!--部署项目的网站需要的信息-->
        <site>
            <!--部署位置的唯一标识符，用来匹配站点和settings.xml文件里的配置-->
            <id>banseon-site</id>
            <!--部署位置的名称-->
            <name>business api website</name>
            <!--部署位置的URL，按protocol://hostname/path形式-->
            <url>
                scp://svn.baidu.com/banseon:/var/www/localhost/banseon-web
            </url>
        </site>
        <!--项目下载页面的URL。如果没有该元素，用户应该参考主页。
      使用该元素的原因是：帮助定位那些不在仓库里的构件（由于license限制）。-->
        <downloadUrl/>
        <!-- 给出该构件在远程仓库的状态。不得在本地项目中设置该元素，
      因为这是工具自动更新的。有效的值有：none（默认），
      converted（仓库管理员从 Maven 1 POM转换过来），partner（直接从伙伴Maven 2仓库同步过来），deployed（从Maven 2实例部 署），verified（被核实时正确的和最终的）。-->
        <status/>
    </distributionManagement>
    <!--以值替代名称，Properties可以在整个POM中使用，也可以作为触发条件（见settings.xml配置文件里activation元素的说明）。格式是<name>value</name>。-->
    <properties/>
</project>
```

## Maven补充学习

### 一、Maven版本规范

maven使用如下几个要素来唯一定位某一个输出物： groupId:artifactId:packaging:version 。比如org.springframework:spring:2.5 。每个部分的解释如下：

1. groupId 公司，团体等。如Apache Software的项目有以org.apache开头的groupId。
2. artifactId 项目的唯一标识符。比如一个helloworld项目就叫helloworld。
3. packaging 项目打包输出的类型，默认是jar。类型为war的项目产生一个web应用。
4. version 一个项目的特定版本。发布的项目有一个固定的版本标识来指向该项目的某一个特定的版本。而正在开发中的项目可以用一个特殊的标识，这种标识给版本加上一个"SNAPSHOT"的标记。
   - maven有自己的版本规范，一般是如下定义` ..-` ，比如1.2.3-beta-01。要说明的是，maven自己判断版本的算法是major,minor,incremental部分用数字比较，qualifier部分用字符串比较，所以要小心 alpha-2和alpha-15的比较关系，最好用 alpha-02的格式。
   - maven在版本管理时候可以使用几个特殊的字符串 SNAPSHOT ,LATEST ,RELEASE 。比如"1.0-SNAPSHOT"。各个部分的含义和处理逻辑如下说明：
     - SNAPSHOT 如果一个版本包含字符串"SNAPSHOT"，Maven就会在安装或发布这个组件的时候将该符号展开为一个日期和时间值，转换为UTC时间。例如，"1.0-SNAPSHOT"会在2010年5月5日下午2点10分发布时候变成1.0-20100505-141000-1。这个词只能用于开发过程中，因为一般来说，项目组都会频繁发布一些版本，最后实际发布的时候，会在这些snapshot版本中寻找一个稳定的，用于正式发布，比如1.4版本发布之前，就会有一系列的1.4-SNAPSHOT，而实际发布的1.4，也是从中拿出来的一个稳定版。
     - LATEST 指某个特定构件的最新发布，这个发布可能是一个发布版，也可能是一个snapshot版，具体看哪个时间最后。
     - RELEASE 指最后一个发布版。

### 二、Maven 项目依赖

#### 1. 多模块依赖和继承

项目结构图：

```
parent
    ├─childA(model层)
    │  └─pom.xml(jar)
    ├─childB(web层)
    │  └─pom.xml(war)
    └─pom.xml(pom)
```

1. parent中执行`mvn install`就能将 childA和childB 一起编译

   parent的pom.xml做如下配置：

   ```xml
   <groupId>com.song</groupId>
   <artifactId>parent</artifactId>
   <version>1.0-SNAPSHOT</version>
   <packaging>pom</packaging>    <!-- pom表示它是一个被继承的模块 -->
   
   <modules>
       <module>childA</module>   <!-- 不加module则不会被联合编译 -->
       <module>childB</module>
   </modules>
   ```

   childA和childB的pom.xml都需要配置parent，防止引入的包冲突(如果不加parent，会分别去编译他们引入的依赖，会重复引入包):

   ```xml
   <!-- childA 的 pom.xml-->
   <parent>
       <artifactId>parent</artifactId>
       <groupId>com.song</groupId>
       <version>1.0-SNAPSHOT</version>
   </parent>
   <modelVersion>4.0.0</modelVersion>
   <artifactId>childA</artifactId>
   <packaging>jar</packaging>
   
   <!-- childB 的 pom.xml-->
   <parent>
       <artifactId>parent</artifactId>
       <groupId>com.song</groupId>
       <version>1.0-SNAPSHOT</version>
   </parent>
   <modelVersion>4.0.0</modelVersion>
   <artifactId>childB</artifactId>
   <packaging>war</packaging>
   ```

2. 子pom间存在引用关系，比如childB引用到了childA的jar包

```
<dependency>
   <groupId>com.module</groupId>
   <artifactId>childA</artifactId>       <!--加上childA的依赖-->
   <version>1.0-SNAPSHOT</version>
</dependency>
```

#### 2. 子项目继承父项目的依赖

parent中加上`<dependencyManagement>`，child项目就可以继承parent项目的依赖，并且在child中可以不用加version了。

```xml
<dependencyManagement>
   <dependencies>
      <dependency>
           <groupId>javax.servlet</groupId>
          <artifactId>servlet-api</artifactId>
          <version>2.5</version>
      </dependency>
   </dependencies>
</dependencyManagement>
```

#### 3. 依赖范围

如果不显示执行 <scope> 属性时，默认` compile`。
scope 属性包括：

1. **compile**（编译范围）：编译范围的`<dependency>`在所有的classpath中可用，同时它们也会被打包
2. **provided**（已提供范围）：表示部署的环境当中有某容器已经提供了该jar包，只在编译classpath（不是运行时）可用。它们不是传递性的，也不会被打包。例如，如果你开发了一个web应用，你可能在编译classpath中需要可用的Servlet API来编译一个servlet，但是你不会想要在打包好的WAR中包含这个Servlet API；这个Servlet API JAR由你的servlet容器（Tomcat）提供。
3. **runtime**（运行时范围）：只在运行和测试系统的时候需要，但在编译的时候不需要。
4. **test**（测试范围）：在一般的 编译和运行时都不需要，它们只有在测试编译和测试运行阶段可用。
5. **system** （系统范围）：该范围不推荐使用（你应该一直尽量去从公共或定制的Maven仓库中引用依赖）

> 详细可参考：[https://maven.apache.org/guid...](https://maven.apache.org/guides/introduction/introduction-to-dependency-mechanism.html#Dependency_Scope)

#### 4. 可选依赖（Optional Dependencies）和依赖排除（Dependency Exclusions）

maven的依赖关系是有传递性的。如：A-->B，B-->C。但有时候，项目A可能不是必需依赖C，因此需要在项目A中排除对A的依赖。在maven的依赖管理中，有两种方式可以对依赖关系进行，分别是可选依赖（Optional Dependencies）以及依赖排除（Dependency Exclusions）。

##### 4.1 可选依赖 optional

当一个项目A依赖另一个项目B时，项目A可能很少一部分功能用到了项目B，此时就可以在A中配置对B的可选依赖。举例来说，一个类似hibernate的项目，它支持对mysql、oracle等各种数据库的支持，但是在引用这个项目时，我们可能只用到其对mysql的支持，此时就可以在这个项目中配置可选依赖。

配置可选依赖的原因：1、节约磁盘、内存等空间；2、避免license许可问题；3、避免类路径问题，等等。

```xml
<dependency>
  <groupId>sample.ProjectB</groupId>
  <artifactId>Project-B</artifactId>
  <version>1.0</version>
  <scope>compile</scope>
  <optional>true</optional>
</dependency>
```

假设以上配置是项目A的配置，即：Project-A --> Project-B。在编译项目A时，是可以正常通过的。

如果有一个新的项目X依赖A，即：Project-X -> Project-A。此时项目X就不会依赖项目B了。如果项目X用到了涉及项目B的功能，那么就需要在pom.xml中重新配置对项目B的依赖。

##### 4.2 依赖排除 exclusions

当一个项目A依赖项目B，而项目B同时依赖项目C，如果项目A中因为各种原因不想引用项目C，在配置项目B的依赖时，可以排除对C的依赖。

示例（假设配置的是A的pom.xml，依赖关系为：A --> B; B --> C）：

```xml
<dependency>
  <groupId>sample.ProjectB</groupId>
  <artifactId>Project-B</artifactId>
  <version>1.0</version>
  <scope>compile</scope>
  <exclusions>
    <exclusion>
      <groupId>sample.ProjectC</groupId>
      <artifactId>Project-C</artifactId>
    </exclusion>
  </exclusions> 
</dependency>
```

当然，对于多重依赖，配置也很简单，参考如下示例：

```
Project-A
   -> Project-B
        -> Project-D 
              -> Project-E <! -- This dependency should be excluded -->
              -> Project-F
   -> Project C
```

A对于E相当于有多重依赖，我们在排除对E的依赖时，只需要在配置B的依赖中进行即可：

```xml
<dependency>
  <groupId>sample.ProjectB</groupId>
  <artifactId>Project-B</artifactId>
  <version>1.0-SNAPSHOT</version>
  <exclusions>
    <exclusion>
      <groupId>sample.ProjectE</groupId>
      <artifactId>Project-E</artifactId>
    </exclusion>
  </exclusions>
</dependency>
```

### 三、Maven插件机制

#### 1. Maven默认插件

不配置Plugin时，Maven默认会使用以下插件。如果针对各个 plugin 有特殊配置的话，需要显示指定 plugin 和 属性配置。

| plugin                 | function                                     | life cycle phase        |
| ---------------------- | -------------------------------------------- | ----------------------- |
| maven-clean-plugin     | 清理上一次执行创建的target文件               | clean                   |
| maven-resources-plugin | 处理资源文件                                 | resources,testResources |
| maven-compiler-plugin  | 编译Java代码                                 | compile、testCompile    |
| maven-surefire-plugin  | 执行单元测试文件                             | test                    |
| maven-jar-plugin       | 创建 jar                                     | package                 |
| maven-install-plugin   | 拷贝jar到本地的maven仓库 .m2/repository 下面 | install                 |
| maven-deploy-plugin    | 发布 jar                                     | deploy                  |
| maven-site-plugin      | 生成文档                                     | site                    |

> maven-site-plugin：将工程所有文档生成网站，生成的网站界面默认和apache的项目站点类似，但是其文档用doxia格式写的，目前不支持docbook，需要用其他插件配合才能支持。需要指出的是，在maven 2.x系列中和maven3.x的site命令处理是不同的，在旧版本中，用 mvn site 命令可以生成reporting节点中的所有报表，但是在maven3中，reporting过时了，要把这些内容作为 maven-site-plugin的configuration的内容才行。详细内容可以参考[http://www.wakaleo.com/blog/2...](http://www.wakaleo.com/blog/292-site-generation-in-maven-3)

```xml
<build>
    <!-- resources 是 maven-resources-plugin 的-->
    <resources>
        <resource>
            <directory>src/main/java</directory>
            <filtering>true</filtering> <!-- filtering 用来表示资源文件中的占位符是否需要被profiles中的属性动态替换，true为需要替换。 -->
            <includes>
                <include>**/*.xml</include>
            </includes>
        </resource>
        <resource>
            <directory>src/main/resources</directory>
            <filtering>true</filtering>
            <includes>
                <include>**/*.properties</include>
                <include>*.xml</include>
                <include>*.dic</include>
                <include>*.txt</include>
            </includes>
        </resource>
        <resource>
            <directory>src/main/resources</directory>
            <filtering>false</filtering>
            <includes>
                <include>*.p12</include>
            </includes>
        </resource>
    </resources>



    <plugins>
        <!-- 
            maven-compiler-plugin编译源代码。
            指定maven编译的jdk版本,如果不指定,maven3默认用jdk 1.5 maven2默认用jdk1.3 
            windows默认使用GBK编码，java项目经常编码为utf8，也需要在compiler插件中指出，否则中文乱码可能会出现编译错
        -->
        <plugin>
            <artifactId>maven-compiler-plugin</artifactId>
            <version>3.1</version>
            <configuration>
                <source>1.8</source>
                <target>1.8</target>
                <encoding>UTF-8</encoding>
            </configuration>
        </plugin>
        
        <!--
            maven-resources-plugin用来处理资源文件，默认的主资源文件目录是src/main/resources。
        -->
        <plugin>
            <groupId>org.apache.maven.plugins</groupId>
            <artifactId>maven-resources-plugin</artifactId>
            <version>2.6</version>
            <configuration>
                <encoding>UTF-8</encoding>
            </configuration>
        </plugin>
    </plugins>
</build>
```

#### 2. Maven常用插件

##### 2.0 spring-boot-maven-plugin

当使用SpringBoot开发项目的时候，会使用到`spring-boot-maven-plugin`插件

> 官方文档：[https://docs.spring.io/spring...](https://docs.spring.io/spring-boot/docs/current/maven-plugin/index.html)

Spring Boot Maven plugin有5个Goals：

| 命令                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| spring-boot:repackage  | 默认goal。在mvn package之后，再次打包可执行的jar/war，<br/>并将mvn package生成的软件包重命名为*.original |
| spring-boot:run        | 运行Spring Boot应用                                          |
| spring-boot:start      | 在mvn integration-test阶段，进行Spring Boot应用生命周期的管理 |
| spring-boot:stop       | 在mvn integration-test阶段，进行Spring Boot应用生命周期的管理 |
| spring-boot:build-info | 生成Actuator使用的构建信息文件build-info.properties          |

其中比较重要的命令是：

```
mvn package spring-boot:repackage
```

执行后会看到生成的两个jar文件，一个是`*.jar`，另一个是`*.jar.original`。
这是由于在执行上述命令的过程中，Maven首先在`package`阶段打包生成`*.jar`文件；然后执行`spring-boot:repackage`重新打包

**我们也可以跳过`repackage`阶段**：

```shell
clean deploy -D spring-boot.repackage.skip=true
```

加上`-D spring-boot.repackage.skip=true`参数即可，此时只会生成一个普通的jar包

##### 2.1 maven-source-plugin

maven-source-plugin提供项目自动将源码打包并发布的功能，在需要发布源码项目的pom.xml文件中添加如下代码即可：

```xml
<plugin>
    <groupId>org.apache.maven.plugins</groupId>
    <artifactId>maven-source-plugin</artifactId>
    <configuration>
    </configuration>
    <executions>
        <execution>
            <id>attach-sources</id>
            <goals>
                <goal>jar</goal>
            </goals>
        </execution>
    </executions>
</plugin>
```

执行 `mvn install`，maven会自动将source install到repository 。
执行 `mvn deploy`，maven会自动将source deploy到remote-repository 。
执行 `mvn source:jar`，单独打包源码。

> **注意**：在多项目构建中，将source-plugin置于顶层或parent的pom中并不会发挥作用，必须置于具体项目的pom中。

##### 2.2 Tomcat插件

tomcat插件有两种：tomcat-maven-plugin 和 tomcat7-maven-plugin，使用方式基本相同。

- tomcat-maven-plugin 插件是org.codehaus.mojo组织提供的，里面的tomcat是6.0.29版本，没有更新了。
- tomcat7-maven-plugin 插件是apache提供的，官网：[http://tomcat.apache.org/mave...](http://tomcat.apache.org/maven-plugin.html)

1. **tomcat7-maven-plugin 插件使用**

   ```xml
   <plugin>
       <groupId>org.apache.tomcat.maven</groupId>
       <artifactId>tomcat7-maven-plugin</artifactId>
       <version>2.2</version>
          <configuration>
             <path>/</path>
             <port>8080</port>
             <uriEncoding>UTF-8</uriEncoding>
             <server>tomcat7</server>
          </configuration>
           <executions>
               <execution>
                   <phase>package</phase>
                   <goals>
                       <goal>run</goal>
                   </goals>
               </execution>
           </executions>
   </plugin>
   ```

   命令：

   ```
   tomcat7:deploy  --部署一个web war包
   tomcat7:reload  --重新加载web war包
   tomcat7:start    --启动tomcat
   tomcat7:stop    --停止tomcat
   tomcat7:undeploy --停止一个war包
   tomcat7:run --启动嵌入式tomcat ，并运行当前项目
   ```

2. **tomcat-maven-plugin 插件使用**

   ```xml
   <plugin>
       <groupId>org.codehaus.mojo</groupId>
       <artifactId>tomcat-maven-plugin</artifactId>
       <version>1.1</version>
       <configuration>
           <path>/helloworld</path>
           <port>8080</port>
           <uriEncoding>UTF-8</uriEncoding>
           <url>http://localhost:8080/manager/html</url>
           <server>tomcat6</server>
           <systemProperties>
               <JAVA_OPTS>-Xms256m -Xmx512m -XX:MaxPermSize=512m</JAVA_OPTS>
             </systemProperties>
       </configuration>
   </plugin>
   ```

   命令：

   ```xml
   tomcat:deploy   --部署一个web war包
   tomcat:reload   --重新加载web war包
   tomcat:start    --启动tomcat
   tomcat:stop    --停止tomcat
   tomcat:undeploy --停止一个war包
   tomcat:run  --启动嵌入式tomcat ，并运行当前项目
   ```

配置参数：
**path**：是访问应用的路径
**port**：是tomcat 的端口号
**uriEncoding**：URL按UTF-8进行编码，这样就解决了中文参数乱码。
**Server**：指定tomcat名称。

##### 2.3 自动部署插件wagon

自动部署包含三个步骤：
编译打包、上传到服务器、在服务器上执行linux命令

###### 2.3.1 文件上传到服务器

Maven项目可使用 mvn install 指令打包，打包完成后包位于target目录下，要想在远程服务器上部署，首先要将包上传到服务器。

首先在本地的setting.xml中配置server的信息，包括id，用户名，密码。（当然也可以在pom.xml里面配置）

```xml
<servers>
    <server>
      <id>linux_server</id>
      <username>user</username>
      <password>password</password>
    </server>
</servers>
```

pom.xml

```xml
<build>
    <extensions>
        <extension>
            <groupId>org.apache.maven.wagon</groupId>
            <artifactId>wagon-ssh</artifactId>
            <version>2.8</version>
        </extension>
    </extensions>
    <plugins>
        <plugin>
            <groupId>org.codehaus.mojo</groupId>
            <artifactId>wagon-maven-plugin</artifactId>
            <version>1.0</version>
            <configuration>
                <serverId>linux_server</serverId>
                <fromFile>target/test.war</fromFile>
                <url>scp://user:password@192.168.20.128/home/tomcat7/webapps</url>
            </configuration>
        </plugin>
    </plugins>
</build>
```

`linux_server`： 在setting.xml中配置的server的id名字
`target/test.war`：是要上传到服务器的文件，一般来说是jar或者war包 `scp://user:password@192.168.20.128/home/tomcat7/webapps`：配置服务器的用户、密码、地址以及文件上传的目录

命令：

```shell
# 对项目进行打包和上传操作
mvn clean install wagon:upload-single 
```

如果觉的wagon命令太长，可以设置 excutions 来配置phase和goals来简化命令。

###### 2.3.2 在服务器上执行linux命令

1. 运行jar文件

```xml
<!-- 
如果运行的命令中没有“-D maven.deploy.skip=true”不配置distributionManagement 则会报错：-DaltDeploymentRepository=id::layout::url parameter 因为不加maven.deploy.skip=true,则会使用maven的deploy，又使用wagon的deploy。而maven的deploy是需要配置distributionManagement的
<distributionManagement>
    <repository>
        <id>${serverid}</id>
        <url>scp://192.168.20.128/home/java/exe</url>
    </repository>
</distributionManagement>
-->

<build>
    <extensions>
        <extension>
            <groupId>org.apache.maven.wagon</groupId>
            <artifactId>wagon-ssh</artifactId>
            <version>2.8</version>
        </extension>
    </extensions>
    <plugins>
        <plugin>
            <groupId>org.codehaus.mojo</groupId>
            <artifactId>wagon-maven-plugin</artifactId>
            <version>1.0</version>
            
            <configuration>
                <fromFile>target/test.jar</fromFile>
                <url>scp://user:password@192.168.20.128/home/java/exe</url>
                <commands>
                    <command>pkill -f /home/java/exe/test.jar</command>  <!-- 杀死原来的进程，-f 是用来查找命令参数，禁止使用pkill java来杀死进程,也可以是 pkill -f test.jar -->
                    <command>nohup java -jar /home/java/exe/test.jar > /home/java/exe/$(date +%Y%m%d-%H%M%S).log &amp; </command> <!-- 重新启动test.jar，&amp; 是xml的转义字符，表示 &-->
                </commands>
                <displayCommandOutputs>true</displayCommandOutputs> <!-- 显示运行命令的输出结果 -->
            </configuration>
        </plugin>
    </plugins>
</build>
```

命令

```shell
<!--install、wagon:upload-single、wagon:sshexec 分别对项目进行打包、上传、运行command命令的操作-->
mvn clean install wagon:upload-single wagon:sshexec
```

2. 上传war包并启动Tomcat

```xml
<build>
   <extensions>
       <extension>
           <groupId>org.apache.maven.wagon</groupId>
           <artifactId>wagon-ssh</artifactId>
           <version>2.8</version>
       </extension>
   </extensions>
   <plugins>
       <plugin>
           <groupId>org.codehaus.mojo</groupId>
           <artifactId>wagon-maven-plugin</artifactId>
           <version>1.0</version>
           
           <configuration>
               <fromFile>target/javawebdeploy.war</fromFile>
               <url>scp://user:password@192.168.20.128/home/tomcat7/webapps</url>
               <commands>
                   <!-- 重启Tomcat -->
                   <command>sh /home/tomcat7/bin/shutdown.sh</command>
                   <command>rm -rf /home/tomcat7/webapps/test</command>
                   <command>sh /home/tomcat7/bin/startup.sh</command>
               </commands>
               <displayCommandOutputs>true</displayCommandOutputs>
           </configuration>
       </plugin>
   </plugins>
</build>
```

命令

```shell
mvn clean install wagon:upload-single wagon:sshexec
```

###### 2.3.3 配置execution

如果觉得 `mvn clean package wagon:upload-single wagon:sshexec` 命令太长了不好记，那么可以配置execution，在运行deploy的同时运行upload-single和sshexec。

```xml
<build>
    <extensions>
        <extension>
            <groupId>org.apache.maven.wagon</groupId>
            <artifactId>wagon-ssh</artifactId>
            <version>2.8</version>
        </extension>
    </extensions>
    <plugins>
        <plugin>
            <groupId>org.codehaus.mojo</groupId>
            <artifactId>wagon-maven-plugin</artifactId>
            <version>1.0</version>
            <executions>
                <execution>
                    <id>upload-deploy</id>
                    <!-- 运行deploy命令时同时运行upload-single和sshexec -->
                    <phase>deploy</phase>
                    <goals>
                        <goal>upload-single</goal>
                        <goal>sshexec</goal>
                    </goals>
                    
                    <configuration>
                        <fromFile>target/test.war</fromFile>
                        <url>scp://user:password@192.168.20.128/home/tomcat7/webapps</url>
                        <commands>
                            <command>sh /home/tomcat7/bin/shutdown.sh</command>
                            <command>rm -rf /coder/tomcat7/webapps/test</command>
                            <command>sh /coder/tomcat7/bin/startup.sh</command>
                        </commands>
                        <displayCommandOutputs>true</displayCommandOutputs>
                    </configuration>
                </execution>
            </executions>
        </plugin>
    </plugins>
</build>
```

部署命令

```xml
<!-- 即可使用mvn clean package来代替mvn clean package wagon:upload-single wagon:sshexec -->

<!--  必须加 -D maven.deploy.skip=true ，表示跳过maven自身的deploy使用wagon的deploy。否则报错“-DaltDeploymentRepository=id::layout::url parameter”  -->
mvn clean deploy -D maven.deploy.skip=true
```

###### 2.3.4. 完整示例配置

首先在本地的setting.xml中配置server的信息，包括id，用户名，密码。（当然也可以在pom.xml里面配置）

```xml
<servers>
    <server>
      <id>linux_server</id>
      <username>user</username>
      <password>password</password>
    </server>
</servers>
```

pom.xml

```shell
<build>
    <extensions>
        <extension>
            <groupId>org.apache.maven.wagon</groupId>
            <artifactId>wagon-ssh</artifactId>
            <version>2.8</version>
        </extension>
    </extensions>
    <plugins>
        <plugin>
            <groupId>org.codehaus.mojo</groupId>
            <artifactId>wagon-maven-plugin</artifactId>
            <version>1.0</version>
            
            <configuration>
                <serverId>linux_server</serverId>
                <url>scp://192.168.20.128/home/tomcat7/webapps</url>
                <displayCommandOutputs>true</displayCommandOutputs> <!-- 显示运行命令的输出结果 -->
            </configuration>
            
            <executions>
                <!-- 将war包上传到服务器并重启服务器 -->
                <execution>
                    <id>upload-war-to-server</id>
                    <phase>deploy</phase>
                    <goals>
                        <goal>upload-single</goal>
                        <goal>sshexec</goal>
                    </goals>
                    <configuration>
                        <fromFile>target/test.war</fromFile>
                        <commands>
                            <command>datefilename=$(date +%Y%m%d-%H%M%S);cp /home/tomcat7/webapps/test.war /home/tomcat7/webapps/test.war.$datefilename</command>  <!--备份旧的war包-->
                            <command>ps -ef | grep /home/tomcat7/ | grep -v grep | awk {'print $2'} | sed -e "s/^/kill -9 /g" | sh</command> <!-- 关闭tomcat7 -->
                            <command>rm -rf /home/tomcat7/webapps/test</command> <!-- 删除test项目 -->
                            <command>export JAVA_HOME=/home/jdk/jdk1.8.0_91;sh /home/tomcat7/bin/startup.sh</command> <!-- 启动tomcat -->
                        </commands>
                    </configuration>
                </execution>
        </plugin>
    </plugins>
</build>
```

部署命令

```shell
# 必须加 -D maven.deploy.skip=true ，表示跳过maven自身的deploy使用wagon的deploy。否则报错“-DaltDeploymentRepository=id::layout::url parameter”
mvn clean deploy -D maven.deploy.skip=true
```

##### 2.4 maven-war-plugin

Maven打包时可以对`web.xml`中的`spring.profiles.active`值进行替换。

先`web.xml`中配置一个占位符`${profiles.active}`:

```xml
<context-param>
    <param-name>spring.profiles.active</param-name>
    <param-value>${profiles.active}</param-value>
</context-param>
```

在`pom.xml`配置`maven-war-plugin`：

```xml
<!-- 打war包时替换占位符 -->
<build>
  <plugin>
    <artifactId>maven-war-plugin</artifactId>
    <version>3.2.2</version>
    <configuration>
      <!-- 过滤Deployment Descriptor并将文件中的占位符替换为pom.xml中对应的<properties>值 -->
      <filteringDeploymentDescriptors>true</filteringDeploymentDescriptors>
    </configuration>
  </plugin>
</build>

<!-- 默认的maven profile -->
<properties>
  <profiles.active>dev</profiles.active>
</properties>

<profiles>
  <profile>
    <id>dev</id>
    <properties>
      <profiles.active>dev</profiles.active>
    </properties>
  </profile>
  <profile>
    <id>release</id>
    <properties>
      <profiles.active>release</profiles.active>
    </properties>
  </profile>
</profiles>
```

以上配置完成后，再通过`mvn package -Pdev`或`mvn package -Preelase`打包后，`${profiles.active}<`占位符就被替换为`dev`或`release`

### 四、Maven控制测试环境和正式环境

#### 1. Maven profiles切换测试环境和正式环境

```xml
<profiles>
    <profile>
        <!-- 本地开发环境 -->
        <id>dev</id>
        <properties>
            <profiles.active>dev</profiles.active>
        </properties>
        <activation>
            <!-- 设置默认激活这个配置 -->
            <activeByDefault>true</activeByDefault>
        </activation>
    </profile>
    <profile>
        <!-- 发布环境 -->
        <id>release</id>
        <properties>
            <profiles.active>release</profiles.active>
        </properties>
    </profile>
    <profile>
        <!-- 测试环境 -->
        <id>beta</id>
        <properties>
            <profiles.active>beta</profiles.active>
        </properties>
    </profile>
</profiles> 



<build>
    <finalName>helloworld</finalName>
    <resources>
        <!-- 先全部不包含 -->
        <resource>
            <directory>src/main/resources</directory>
            <excludes>
                <exclude>config/</exclude>
            </excludes>
        </resource>
        <!-- 再指定需要包含的文件夹 -->
        <resource>
            <directory>src/main/resources/config/${profiles.active}</directory>
            <targetPath>.</targetPath>
        </resource>
    </resources>
</build>
```

id代表这个环境的唯一标识，在 mvn install -Pdev 来指定。
此properties定义了三个环境，分别是dev（开发环境）、beta（测试环境）、release（发布环境）
activeByDefault=true代表如果不指定某个固定id的profile，那么就使用这个环境

**使用 `mvn install -Pdev`会将 id 为 dev 的 profile 中的`<properties>`定义的属性`profiles.active`自动替换`${profiles.active}`占位符的变量。最终build到classpath的资源文件由maven-resources-plugin来指定，为src/main/resources/config/dev文件下的所有文件。**

#### 2. Spring Framework profile整合Maven profile

如果想要整合Maven profile和Spring Framework profile，Maven打包时可以对`web.xml`中的`spring.profiles.active`值进行替换。

先`web.xml`中配置一个占位符`${profiles.active}`:

```xml
<context-param>
    <param-name>spring.profiles.active</param-name>
    <param-value>${profiles.active}</param-value>
</context-param>
```

在`pom.xml`配置`maven-war-plugin`：

```xml
<!-- 打war包时替换占位符 -->
<build>
  <plugin>
    <artifactId>maven-war-plugin</artifactId>
    <version>3.2.2</version>
    <configuration>
      <!-- 过滤Deployment Descriptor并将文件中的占位符替换为pom.xml中对应的<properties>值 -->
      <filteringDeploymentDescriptors>true</filteringDeploymentDescriptors>
    </configuration>
  </plugin>
</build>

<!-- 默认的maven profile -->
<properties>
  <profiles.active>dev</profiles.active>
</properties>

<profiles>
  <profile>
    <id>dev</id>
    <properties>
      <profiles.active>dev</profiles.active>
    </properties>
  </profile>
  <profile>
    <id>release</id>
    <properties>
      <profiles.active>release</profiles.active>
    </properties>
  </profile>
</profiles>
```

以上配置完成后，再通过`mvn package -Pdev`或`mvn package -Preelase`打包后，`${profiles.active}<`占位符就被替换为`dev`或`release`

### 五、Maven 变量

#### 1. 内置属性

- **${basedir}** represents the directory containing pom.xml
- **${version}** equivalent to ${project.version } or ${pom.version }

#### 2. Pom/Project properties

所有pom中的元素都可以用 project. 前缀进行引用,以下是部分常用的

- **${project.build.directory}** results in the path to your "target" dir, this is the same as ${pom.project.build.directory}
- **${project.build.outputDirectory}** results in the path to your "target/classes" dir
- **${project.name}** refers to the name of the project.
- **${project.version}** refers to the version of the project.
- **${project.build.finalName}** refers to the final name of the file created when the built project is packaged

#### 3. 本地用户设定

所有用的的 settings.xml 中的设定都可以通过 settings. 前缀进行引用

- **${settings.localRepository}** refers to the path of the user's local repository.
- **${maven.repo.local}** also works for backward compatibility with maven1

#### 4. 环境变量

系统的环境变量通过 env. 前缀引用

- **${env.M2_HOME}** returns the Maven2 installation path.
- **${java.home}** specifies the path to the current JRE_HOME environment use with relative paths to get for example: <jvm>${java.home}../bin/java.exe</jvm>

#### 5. java系统属性

所有JVM中定义的java系统属性.

#### 6. pom.xml自定义变量

```xml
<project> 
    ... 
    <properties> 
        <project.build.finalName>hellowolrld</project.build.finalName> 
    </properties> 
    ... 
</project> 
```

则引用 ${project.build.finalName} 就会得到值 hellowolrld

#### 7. parent 工程的变量

parent工程的pom.xml中的变量用前缀 `${project.parent}` 引用. 上级工程的版本也可以这样引用: `${parent.version }`.



## 可能遇到的问题

Maven约定资源目录在src/main/resource/下，但有时我们的配置文件可能不在这里，可以在build中配置resources，防止资源导入错误

```xml
<build>
    <resources>
        <resource>
            <directory>src/main/resources</directory>
            <includes>
                <include>**/*.xml</include>
                <include>**/*.properties</include>
            </includes>
            <filtering>true</filtering>
        </resource>
        <resource>
            <directory>src/main/java</directory>
            <includes>
                <include>**/*.xml</include>
                <include>**/*.properties</include>
            </includes>
            <filtering>true</filtering>
        </resource>
    </resources>
</build>
```

Maven打包时跳过单元测试

```xml
<properties>
    <!--跳过单元测试 -->
    <maven.test.skip>true</maven.test.skip>
    <maven.javadoc.skip>true</maven.javadoc.skip>
</properties>
```