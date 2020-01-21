set encoding=utf-8
set nocompatible
set nu
set tabstop=4
set shiftwidth=4
set expandtab
set smartindent
set autoindent
set showmatch
set comments=sl:/*,mb:\ *,elx:\ */
set hlsearch
set ignorecase
set smartcase
set colorcolumn=110
highlight ColorColumn ctermbg=darkgray
syntax on

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'vim-airline/vim-airline'
Plugin 'scrooloose/nerdtree'
Plugin 'airblade/vim-gitgutter'
Plugin 'tpope/vim-fugitive'
Plugin 'nanotech/jellybeans.vim'
"Plugin 'Valloric/YouCompleteMe'
call vundle#end()

color jellybeans
let g:airline_powerline_fonts = 1
"let g:ycm_global_ycm_extra_conf = "~/.vim/.ycm_extra_conf.py"
