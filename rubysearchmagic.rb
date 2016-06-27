# William Pereira
require 'ferret'
include Ferret

magic = Index::Index.new()  
puts ("Escolha uma palavra para procura:")
palavra = gets
puts ("---------------------------------------")
puts ("Os arquivos que contem a palavra são:")
puts ("---------------------------------------")
magic.search_each(palavra) do | id, score |  
	puts ("Arquivo: #{magic[id][:title]}")  
end  