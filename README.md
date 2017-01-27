# GSL interface for Ruby with Numo::NArray

* Pre-alpha version under development.
* [GitHub site](https://github.com/ruby-numo/gsl)

## Implemented Modules

* [Numo::GSL API document](http://ruby-numo.github.io/gsl/doc/)
  * [Mathematical Functions](http://ruby-numo.github.io/gsl/doc/Numo/GSL.html)
  * [Constants](http://ruby-numo.github.io/gsl/doc/Numo/GSL/Const.html)
  * [Special Functions](http://ruby-numo.github.io/gsl/doc/Numo/GSL/Sf.html)
  * [Statistics](http://ruby-numo.github.io/gsl/doc/Numo/GSL/Stats.html)

More modules will be implemented.

## Installation

* Install [Numo::NArray](https://github.com/ruby-numo/narray)
* Install [GSL - GNU Scientific Library](http://www.gnu.org/software/gsl/) - version 2.1

* Install Numo::GSL
  ```shell
$ git clone git://github.com/ruby-numo/gsl.git
$ cd gsl
$ rake build
$ gem install pkg/numo-gsl-*.gem
```

rubygems is to be created.

# Quick start

If you're familiar with Docker, the following commands should work in most cases:

```
git clone https://github.com/ruby-numo/gsl
cd gsl
docker build -t numogsl .
docker run -d -p 8888:8888 numogsl start-notebook.sh --NotebookApp.token=''
```

and open a web browser to http://localhost:8888 .

Our Docker image is based on Minimal Jupyter Notebook Stack. See https://github.com/jupyter/docker-stacks/tree/master/minimal-notebook for more details on the Docker command options.
