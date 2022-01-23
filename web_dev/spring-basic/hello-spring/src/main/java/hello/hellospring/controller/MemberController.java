package hello.hellospring.controller;

import hello.hellospring.domain.Member;
import hello.hellospring.service.MemberService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
public class MemberController {

    // 이걸 = new ~~ 하는건 별로
    // 스프링 컨테이너를 받아서 쓰는게 좋다.
    // 여러 서비스에서 가져와서 쓸 수 있음
    // 즉 하나의 컨테이너로만 돌려쎠도 됨
    private final MemberService memberService;

    // autowired : memberService를 스프링 컨테이너에서 자동으로 연결
    // 의존관계 주입 Controller -> Service
    @Autowired
    public MemberController(MemberService memberService) {
        this.memberService = memberService;
    }

    // url/members/new 로 들어올경우 실행
    @GetMapping("/members/new")
    public String createForm() {
        return "members/createMemberForm";
    }

    // creatememberform에서 action url의 post방식
    // 데이터 등록 = post / 조회 = get 사용
    @PostMapping("/members/new")
    public String create(MemberForm form) {
        Member member = new Member();
        member.setName(form.getName());

        memberService.join(member);
        return "redirect:/";
    }
}
