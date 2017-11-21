function [ ] = plot_pdf( H, path, size )
%plotpdf Save plots to pdf
%   H - handler to figure (h = fihure();)
%   path - filename to save with path
%   size - [width heigth] in pixel
% Example:
% H = figure();
% x = 0:1:100;
% plot(x,x.^2);
% plot_pdf(H, 'plot_pdf_example', [600,400]);

set(H,'Position', [100 100 size(1) size(2)]); %figure resolution
set(H,'PaperUnits','points'); % px
set(H,'PaperSize',[size(1) size(2)]); % size of image    
set(H,'PaperPosition',[0 0 size(1) size(2)]); %top position
print(H,'-dpdf', strcat(path));

end

